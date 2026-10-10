from pathlib import Path
import json
import math
import os
import re
import subprocess
import sys

from PIL import Image, ImageDraw, ImageFont

# ============================================================
# SETTINGS
# ============================================================

ROOT = Path(r"D:\pty\Python\Prassidha\AI_Lab")
SCREENSHOTS = ROOT / "screenshots"
LOG_FILE = ROOT / "automation_log.txt"

TIMEOUT = 30            # seconds before a program is killed
FONT_SIZE = 18
COLS = 110              # terminal width (long lines wrap here)
PADDING = 20
MAX_ROWS = 70           # max lines per image for long plain output
SPLIT_LOOKBACK = 10     # look back this many lines for a blank line to split on
STEP_FRAMES = True      # save a screenshot after every input for screen-style programs
RANDOM_SEED = 7         # controls the "auto" human moves (change for a different game)

BG = (12, 12, 12)
FG = (204, 204, 204)
PROMPT = (97, 214, 214)
ERR = (241, 76, 76)
DIM = (118, 118, 118)

# ============================================================
# TEST INPUTS  (key = path relative to ROOT; "Lab 6" / "Lab_6" both work)
# Use "auto" = human picks a random free cell (tic-tac-toe)
# ============================================================

INPUTS = {
    "Lab_1/2.py": ["10", "5"],
    "Lab_1/4.py": ["25"],
    "Lab_1/5.py": ["20", "4"],
    "Lab_1/7.py": ["20", "10"],
    "Lab_1/8.py": ["25"],
    "Lab_1/9.py": ["85"],
    "Lab_1/10.py": ["10", "20", "15"],
    "Lab_1/11.py": ["20"],
    "Lab_1/16.py": ["Artificial Intelligence"],
    "Lab_1/17.py": ["Python"],
    "Lab_1/18.py": ["madam"],
    "Lab_1/19.py": ["7"],
    "Lab_1/20.py": ["10"],
    "Lab_1/21.py": ["7"],
    "Lab_1/22.py": ["85"],
    "Lab_1/23.py": ["2024"],
    "Lab_1/25.py": ["Artificial Intelligence"],
    "Lab_1/26.py": ["Python"],
    "Lab_1/27.py": ["25", "50", "75", "10", "30", "60", "90"],

    # Lab 6: AI plays X (perfect minimax), human plays O automatically
    "Lab_6/tic_tac_toe_compact_layout.py": ["auto"] * 10,
}


def key(rel: str) -> str:
    return rel.lower().replace(" ", "_")


INPUT_LOOKUP = {key(k): v for k, v in INPUTS.items()}

# ============================================================
# WRAPPER (runs inside the subprocess)
#  - input() prints the prompt, the typed value, and a newline
#  - "auto" picks a random free cell from the script's `board`
#  - os.system("cls"/"clear") becomes an ANSI clear-screen
#  - \x1e is a marker used to take a step screenshot
# ============================================================

WRAPPER = r'''
import sys, os, runpy, builtins, json, random

script = sys.argv[1]
values = json.loads(sys.argv[2])
rng = random.Random(int(sys.argv[3]))
it = iter(values)

_orig_system = os.system
def fake_system(cmd):
    if str(cmd).strip().lower() in ("cls", "clear"):
        sys.stdout.write("\x1b[2J\x1b[H")
        sys.stdout.flush()
        return 0
    return _orig_system(cmd)
os.system = fake_system

def fake_input(prompt=""):
    sys.stdout.write(str(prompt))
    try:
        value = next(it)
    except StopIteration:
        sys.stdout.write("\n")
        raise EOFError("no test input provided for this prompt")
    if value == "auto":
        board = sys._getframe(1).f_globals.get("board")
        free = [str(i + 1) for i, c in enumerate(board) if c == " "] if isinstance(board, list) else []
        value = rng.choice(free) if free else "1"
    sys.stdout.write(value + "\n\x1e")
    sys.stdout.flush()
    return value

builtins.input = fake_input
sys.argv = [script]
runpy.run_path(script, run_name="__main__")
'''

# ============================================================
# MINI TERMINAL EMULATOR
# ============================================================

ANSI = re.compile(r"\x1b\[([0-9;?]*)([A-Za-z])")


class Screen:
    def __init__(self, cols):
        self.cols = cols
        self.rows = []          # list of rows; each row = list of (char, color)
        self.r = 0
        self.c = 0
        self.color = FG
        self.frames = []
        self.used_cursor = False

    def _ensure(self, r):
        while len(self.rows) <= r:
            self.rows.append([])

    def _put(self, ch):
        if self.c >= self.cols:
            self.r += 1
            self.c = 0
        self._ensure(self.r)
        row = self.rows[self.r]
        while len(row) <= self.c:
            row.append((" ", self.color))
        row[self.c] = (ch, self.color)
        self.c += 1

    def _csi(self, params, cmd):
        nums = [int(x) if x.isdigit() else 0 for x in params.replace("?", "").split(";")] if params else []

        def arg(k, default):
            return nums[k] if len(nums) > k and nums[k] else default

        if cmd in "Hf":
            self.used_cursor = True
            self.r = arg(0, 1) - 1
            self.c = arg(1, 1) - 1
        elif cmd == "J":
            self.used_cursor = True
            mode = nums[0] if nums else 0
            if mode in (2, 3):
                self.rows = []
            else:
                self._ensure(self.r)
                self.rows[self.r] = self.rows[self.r][:self.c]
                del self.rows[self.r + 1:]
        elif cmd == "K":
            self._ensure(self.r)
            mode = nums[0] if nums else 0
            self.rows[self.r] = [] if mode == 2 else self.rows[self.r][:self.c]
        elif cmd == "A":
            self.r = max(0, self.r - arg(0, 1))
        elif cmd == "B":
            self.r += arg(0, 1)
        elif cmd == "C":
            self.c += arg(0, 1)
        elif cmd == "D":
            self.c = max(0, self.c - arg(0, 1))
        # colours (m) and everything else are ignored

    def feed(self, text, color=None):
        if color is not None:
            self.color = color
        i, n = 0, len(text)
        while i < n:
            ch = text[i]
            if ch == "\x1b":
                m = ANSI.match(text, i)
                if m:
                    self._csi(m.group(1), m.group(2))
                    i = m.end()
                else:
                    i += 1
                continue
            if ch == "\n":
                self.r += 1
                self.c = 0
            elif ch == "\r":
                self.c = 0
            elif ch == "\t":
                for _ in range(8 - self.c % 8):
                    self._put(" ")
            elif ch == "\x08":
                self.c = max(0, self.c - 1)
            elif ch == "\x1e":
                self.frames.append([list(row) for row in self.rows])
            elif ch >= " ":
                self._put(ch)
            i += 1


def trim(rows):
    out = []
    for row in rows:
        row = list(row)
        while row and row[-1][0] == " ":
            row.pop()
        out.append(row)
    while out and not out[-1]:
        out.pop()
    return out

# ============================================================
# FILE DISCOVERY
# ============================================================

def normalize(path: Path) -> str:
    return path.relative_to(ROOT).as_posix()


def lab_sort_key(path: Path):
    m = re.search(r"lab[_ ]?(\d+)", path.parent.name, re.IGNORECASE)
    lab = int(m.group(1)) if m else 999
    m = re.match(r"(\d+)", path.stem)
    num = int(m.group(1)) if m else 999999
    return (lab, num, normalize(path).lower())


def find_files():
    excluded = {"automate.py", "automate_interactive.py", "modified_automator.py",
                "automate_screenshots.py", "automate_ps_cropped.py"}
    files = []
    for p in ROOT.rglob("*.py"):
        if p.name in excluded or "screenshots" in p.parts:
            continue
        parent = p.parent.name.lower().replace(" ", "_")
        if re.match(r"lab_[1-6]", parent):
            files.append(p)
    return sorted(files, key=lab_sort_key)

# ============================================================
# RUN A PROGRAM
# ============================================================

def run_program(path: Path):
    values = INPUT_LOOKUP.get(key(normalize(path)), [])
    env = {**os.environ, "PYTHONIOENCODING": "utf-8", "PYTHONUTF8": "1"}
    try:
        result = subprocess.run(
            [sys.executable, "-u", "-c", WRAPPER, str(path),
             json.dumps(values), str(RANDOM_SEED)],
            cwd=path.parent, capture_output=True, text=True,
            encoding="utf-8", errors="replace", timeout=TIMEOUT, env=env,
        )
        return result.stdout, result.stderr, result.returncode
    except subprocess.TimeoutExpired as e:
        out, err = e.stdout or "", e.stderr or ""
        if isinstance(out, bytes):
            out = out.decode("utf-8", "replace")
        if isinstance(err, bytes):
            err = err.decode("utf-8", "replace")
        return out, err + f"\n[Timed out after {TIMEOUT}s]", None

# ============================================================
# RENDER
# ============================================================

def load_font():
    for c in [r"C:\Windows\Fonts\consola.ttf", r"C:\Windows\Fonts\cour.ttf",
              "DejaVuSansMono.ttf"]:
        try:
            return ImageFont.truetype(c, FONT_SIZE)
        except OSError:
            continue
    return ImageFont.load_default()


FONT = load_font()


def split_pages(rows):
    """Even pages, preferring to break on blank lines. No line is dropped."""
    n = len(rows)
    if n <= MAX_ROWS:
        return [rows]
    pages_needed = math.ceil(n / MAX_ROWS)
    target = math.ceil(n / pages_needed)
    pages, start = [], 0
    while start < n:
        end = min(start + target, n)
        if end < n:
            for k in range(end, max(start + 1, end - SPLIT_LOOKBACK), -1):
                if not rows[k - 1]:
                    end = k
                    break
        pages.append(rows[start:end])
        start = end
    return pages


def draw(rows, dest, ncols, footer=None):
    rows = list(rows)
    if footer:
        rows += [[], [(ch, DIM) for ch in footer]]

    char_w = FONT.getlength("M")
    ascent, descent = FONT.getmetrics()
    line_h = ascent + descent + 4

    width = int(max(ncols, 60) * char_w + PADDING * 2)
    height = int(max(len(rows), 1) * line_h + PADDING * 2)

    img = Image.new("RGB", (width, height), BG)
    d = ImageDraw.Draw(img)

    y = PADDING
    for row in rows:
        k = 0
        while k < len(row):
            color = row[k][1]
            j, text = k, ""
            while j < len(row) and row[j][1] == color:
                text += row[j][0]
                j += 1
            d.text((PADDING + k * char_w, y), text, font=FONT, fill=color)
            k = j
        y += line_h
    img.save(dest)


def render(path: Path, stdout: str, stderr: str, base: Path):
    scr = Screen(COLS)
    scr.feed(f'PS {path.parent}> python "{path.name}"\n', PROMPT)
    scr.feed(stdout.replace("\r\n", "\n"), FG)
    if stderr.strip():
        if scr.c:
            scr.feed("\n")
        scr.feed(stderr.replace("\r\n", "\n").strip() + "\n", ERR)

    final = trim(scr.rows)
    steps = [trim(f) for f in scr.frames]
    ncols = max((len(r) for r in final + [r for f in steps for r in f]), default=0)

    saved = []

    # step screenshots (only for screen-style programs that move the cursor / clear)
    if STEP_FRAMES and scr.used_cursor and steps:
        for k, frame in enumerate(steps, 1):
            dest = base.with_name(f"{base.name}_step{k:02d}.png")
            draw(frame, dest, ncols)
            saved.append(dest)

    pages = split_pages(final)
    total = len(pages)
    for i, page in enumerate(pages, 1):
        footer = f"[ part {i} of {total} ]" if total > 1 else None
        if total == 1:
            dest = base.with_name(base.name + ".png")
        else:
            dest = base.with_name(f"{base.name}_part{i}.png")
        draw(page, dest, ncols, footer)
        saved.append(dest)
    return saved


def output_path(path: Path, index: int) -> Path:
    """Base path WITHOUT extension."""
    folder = SCREENSHOTS / path.relative_to(ROOT).parts[0]
    folder.mkdir(parents=True, exist_ok=True)
    safe = re.sub(r"[^A-Za-z0-9_.-]+", "_", path.stem)
    return folder / f"{index:03d}_{safe}"

# ============================================================
# MAIN
# ============================================================

def main():
    if not ROOT.exists():
        raise SystemExit(f"Root folder does not exist:\n{ROOT}")

    files = find_files()
    if not files:
        raise SystemExit("No Python lab files found.")

    print("=" * 70)
    print("AI LAB 1-6 - OUTPUT SCREENSHOT GENERATOR")
    print("=" * 70)
    print(f"Root: {ROOT}")
    print(f"Python programs: {len(files)}\n")

    SCREENSHOTS.mkdir(parents=True, exist_ok=True)
    successful, failed, warnings = [], [], []

    for index, path in enumerate(files, 1):
        rel = normalize(path)
        print(f"[{index:02d}/{len(files):02d}] {rel}")
        try:
            stdout, stderr, code = run_program(path)
            saved = render(path, stdout, stderr, output_path(path, index))
            successful.append(rel)
            for s in saved:
                print(f"    OK -> {s}")
            if code != 0:
                last = (stderr.strip().splitlines() or [f"exit code {code}"])[-1]
                warnings.append((rel, last))
                print("    WARNING: program exited with an error (see image)")
        except Exception as exc:
            failed.append((rel, repr(exc)))
            print(f"    ERROR -> {exc}")

    with LOG_FILE.open("w", encoding="utf-8") as log:
        log.write("AI LAB OUTPUT SCREENSHOT LOG\n" + "=" * 70 + "\n\n")
        log.write(f"Root: {ROOT}\n")
        log.write(f"Programs found: {len(files)}\n")
        log.write(f"Programs captured: {len(successful)}\n")
        log.write(f"Failures: {len(failed)}\n")
        log.write(f"Programs with runtime errors: {len(warnings)}\n\n")
        log.write("SUCCESSFUL:\n")
        for item in successful:
            log.write(f"  {item}\n")
        log.write("\nRUNTIME ERRORS IN PROGRAM:\n")
        for item, msg in warnings:
            log.write(f"  {item}: {msg}\n")
        log.write("\nFAILED:\n")
        for item, err in failed:
            log.write(f"  {item}: {err}\n")

    print("\n" + "=" * 70)
    print("FINISHED")
    print("=" * 70)
    print(f"Programs captured: {len(successful)}/{len(files)}")
    print(f"Folder: {SCREENSHOTS}")
    print(f"Log:    {LOG_FILE}")


if __name__ == "__main__":
    main()