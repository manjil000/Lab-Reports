# AI Lab Output Screenshot Generator

Automatically runs your Python lab programs (Lab 1 to Lab 6), types the test inputs for you, and saves the output as terminal-style PNG screenshots. It also plays the Tic-Tac-Toe game for you (AI vs. an automatic human player).

You do **not** need to touch the mouse or keyboard while it runs, and it never types into your VS Code editor.

---

## Table of Contents

1. [What you need](#1-what-you-need)
2. [Download the project from GitHub](#2-download-the-project-from-github)
3. [Folder structure](#3-folder-structure)
4. [Install the requirement](#4-install-the-requirement)
5. [Change the settings (Find and Replace)](#5-change-the-settings-find-and-replace)
6. [Run the script](#6-run-the-script)
7. [Where are my screenshots?](#7-where-are-my-screenshots)
8. [Adding or changing test inputs](#8-adding-or-changing-test-inputs)
9. [Tic-Tac-Toe automatic play](#9-tic-tac-toe-automatic-play)
10. [Optional tweaks](#10-optional-tweaks)
11. [Troubleshooting](#11-troubleshooting)


### (THis is a  very imp step) How to make output of your name ===> Replace your Name in VS Code that's  it!!

Note: if this step is not performed and the code is ran, then the output may have different names. Also 'asd123' is  fixed below [type as it is]

1. Open the AI_LAB folder in VS Code. (the entire folder)
2. Press **Ctrl + H** to open **Find and Replace**.
   - (**Ctrl + F** opens plain **Find** only. It lets you search but not replace. Press Ctrl + H when you want to replace.)
   - On macOS use **Cmd + F** and **Cmd + Option + F**.
3. Type asd123 and the type <YOUR_FULL_NAME> in  second box with '>' this arrow.
4. Click **Replace All** (the double arrow icon), or press **Ctrl + Alt + Enter**.



## 1. What you need

- **Python 3.8 or newer.** Check by opening a terminal and typing `python --version`.
- **Pillow** (a Python image library). Installation is in step 4.
- **VS Code** (recommended, but any terminal works).
- Windows is the default. macOS and Linux work too, see [Troubleshooting](#11-troubleshooting).

---

## 2. Download the project from GitHub

Pick **one** of the two ways.

### Option A: Download ZIP (easiest)

1. Open the GitHub page of this project.
2. Click the green **Code** button.
3. Click **Download ZIP**.
4. Right-click the downloaded ZIP and choose **Extract All...**.
5. Move the extracted folder somewhere easy, for example `D:\AI_Lab`.

### Option B: Git clone

```
git clone https://github.com/manjil000/Lab-Reports.git
cd Lab-Reports/4th\ sem/AI/Artificial\ Intelligence\ labs/lab_codes
```

Then open the folder in VS Code: **File > Open Folder...**

---

## 3. Folder structure

Your project folder (called `ROOT` in the script) should look like this:

```
AI_Lab/                          <-- ROOT folder
|-- automate_screenshots.py      <-- the script you run
|-- Lab_1/
|   |-- 2.py
|   |-- 4.py
|   `-- ...
|-- Lab_2/
|-- Lab 3/                       <-- spaces are fine too
|-- Lab 4/
|-- Lab 5/
|   `-- mazesolver.py and others
`-- Lab_6/
    -- perceptron.py
    `-- tic_tac_toe_compact_layout.py
    -- others...
```

Important rules:

- Lab folder names must start with `Lab_` or `Lab ` followed by a number from **1 to 6**. Both `Lab_5` and `Lab 5` work.
- Your `.py` files must sit **directly inside** a lab folder, not in a sub-folder of it.
- The folders `screenshots` and `automation_log.txt` are created automatically. Don't create them yourself.

---

## 4. Install the requirement

Open a terminal in VS Code (**Terminal > New Terminal**) and run:

```
pip install pillow
```

You only need to do this once. If `pip` isn't recognised, try:

```
python -m pip install pillow
```

---

## 5. Change the settings (Find and Replace)

After downloading, the script still points at **the original author's folder**. You must change it so it points at **your** folder.


### Change 1: your folder path (REQUIRED)

Else the output will contain others name(i.e Prassidha)

| Find | Replace with |
|------|--------------|
| `D:\pty\Python\Prassidha\AI_Lab` | the full path to **your** folder |

Example: if your folder is `C:\Users\Sita\Documents\AI_Lab`, replace with `C:\Users\Sita\Documents\AI_Lab`.

Tips:

- To copy your folder path: in File Explorer, click the address bar, press **Ctrl + C**.
- The line in the script looks like `ROOT = Path(r"...")`. Keep the `r` before the quotes and keep the quotes. Only change the text between them.
- Use a single backslash `\` in this line. The `r` takes care of it.

### Change 2: your file names (if yours are different)

The `INPUTS` dictionary links each program to the answers that get typed in. The format is:

```python
"FolderName/file_name.py": ["answer1", "answer2"],
```

If your files have different names than the examples, use Find and Replace:

| Find | Replace with | Why |
|------|--------------|-----|
| `Lab_1/2.py` | `Lab_1/your_file.py` | rename one entry |
| `Lab_6/tic_tac_toe_compact_layout.py` | `Lab_6/your_game.py` | use your own game file name |
| `Lab_1/` | `Lab_2/` | move *all* entries of a lab to another lab folder |

The folder part and file name are **not** case-sensitive, and `Lab 5` and `Lab_5` count as the same.

### Change 3: scripts you want skipped

Find this block in the script:

```python
excluded = {"automate.py", "automate_interactive.py", "modified_automator.py",
            "automate_screenshots.py", "automate_ps_cropped.py"}
```

Add the name of any `.py` file that should **not** be run (helper scripts, old versions, etc.):

```python
excluded = {"automate_screenshots.py", "my_helper.py"}
```

### Change 4: how many labs to include

Find:

```
lab_[1-6]
```

Replace with `lab_[1-9]` to include Labs 1 to 9. (This only works for single-digit lab numbers.)

---

## 6. Run the script

1. Open the **ROOT** folder in VS Code.
2. Open a terminal (**Ctrl + `** or **Terminal > New Terminal**).
3. Run:

```
python automate_screenshots.py
```

If your terminal is not already inside the project folder, give the full path instead:

```
python "D:\path\to\AI_Lab\automate_screenshots.py"
```

You will see progress like this:

```
[01/19] Lab_1/2.py
    OK -> D:\...\screenshots\Lab_1\001_2.png
[02/19] Lab_1/4.py
    OK -> D:\...\screenshots\Lab_1\002_4.png
...
FINISHED
Programs captured: 19/19
```

Everything runs in the background, so you can keep using your computer normally.

---

## 7. Where are my screenshots?

All screenshots go into a `screenshots` folder **inside your ROOT folder**, with one sub-folder per lab:

```
AI_Lab/
`-- screenshots/
    |-- Lab_1/
    |   |-- 001_2.png
    |   |-- 002_4.png
    |   `-- ...
    |-- Lab 5/
    |   |-- 012_perceptron_part1.png
    |   |-- 012_perceptron_part2.png
    |   `-- ...
    `-- Lab_6/
        |-- 019_tic_tac_toe_compact_layout_step01.png
        |-- 019_tic_tac_toe_compact_layout_step02.png
        `-- 019_tic_tac_toe_compact_layout.png
```

What the file names mean:

| File name | Meaning |
|-----------|---------|
| `012_perceptron.png` | Short output: one image with the whole output |
| `012_perceptron_part1.png`, `_part2.png`, ... | Long output split into several images. Nothing is dropped. They are in reading order, and each shows `[ part x of y ]` at the bottom |
| `019_..._step01.png`, `_step02.png`, ... | Screen-style programs (like Tic-Tac-Toe): the screen after each input |
| `019_....png` (no suffix) | The final screen |

- The leading number (`012`) is the program's position in the full list, so files sort in the right order. If you add or remove programs, these numbers change on the next run.
- Running the script again **overwrites** the older screenshots with the same name.

**The log file** is saved at `AI_Lab/automation_log.txt`. It lists which programs succeeded, which crashed (with the last error line), and which failed to render.

**Quick way to open the folder (Windows):** in the terminal run

```
explorer screenshots
```

---

## 8. Adding or changing test inputs

Whenever a program asks something with `input()`, the script types the next answer from its list, in order.

Example program:

```python
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
```

Add this to `INPUTS` (inside the `{ }`, with a comma at the end of each line):

```python
"Lab_2/add_numbers.py": ["10", "5"],
```

Rules:

- Every answer is written as text in quotes, even numbers: `"10"`, not `10`.
- The answers are used in the same order as the program's questions.
- If the list has **fewer** answers than the program asks for, the screenshot shows a red `EOFError`. Add more answers.
- If the list has **more** answers than needed, the extra ones are simply unused.
- Programs with no `input()` don't need an entry at all.

---

## 9. Tic-Tac-Toe automatic play

The script plays the game for you:

- **AI = X**, always plays perfectly (minimax).
- **Human = O**, plays automatically when you use `"auto"`.

In `INPUTS`:

```python
"Lab_6/tic_tac_toe_compact_layout.py": ["auto"] * 10,
```

This gives the human 10 automatic turns (more than enough for one game). Each `"auto"` picks a random empty cell.

Options:

- **Same game every time:** the moves are seeded, so each run gives the same game.
- **Different game:** change `RANDOM_SEED = 7` to another number (find `RANDOM_SEED` with Ctrl + F).
- **Your own moves:** replace `"auto"` with cell numbers 1 to 9, e.g. `["5", "1", "9"]`.
- **Show only the final screen:** set `STEP_FRAMES = False`.

`"auto"` works for games that keep their grid in a global list named `board`.

**Optional fix for leftover characters** in the game screenshots: in the game file, change `print_at` to:

```python
def print_at(row, col, text=""):
    print(f"\033[{row};{col}H\033[K{text}", end="", flush=True)
```

---

## 10. Optional tweaks

Use **Ctrl + F** to jump to any of these names at the top of the script, then edit the number.

| Setting | Default | What it does |
|---------|---------|--------------|
| `TIMEOUT` | `30` | Seconds before a stuck program is stopped |
| `FONT_SIZE` | `18` | Text size in the screenshots |
| `COLS` | `110` | Width of the "terminal" before long lines wrap |
| `MAX_ROWS` | `70` | Maximum lines per image. Lower = more, shorter images. Higher = fewer, taller images | #note if u want your image size to be short make this 45
| `STEP_FRAMES` | `True` | Save a screenshot after each input for screen-style programs |
| `RANDOM_SEED` | `7` | Controls the automatic human moves |
| `BG`, `FG`, `PROMPT`, `ERR` | colours | Background, text, prompt line and error colours (R, G, B) |

---

## 11. Troubleshooting

| Problem | Fix |
|---------|-----|
| `No module named 'PIL'` | Run `pip install pillow` |
| `Root folder does not exist` | `ROOT` is wrong. Redo [Change 1](#change-1-your-folder-path-required) |
| `No Python lab files found` | Lab folders must be named like `Lab_1` or `Lab 1`, and the `.py` files must be directly inside them |
| `'python' is not recognized` | Try `py automate_screenshots.py`, or reinstall Python and tick **Add Python to PATH** |
| A screenshot shows a red `EOFError` | The program asked for more input than listed. Add more answers in `INPUTS` |
| A screenshot shows `[Timed out after 30s]` | The program waits for something (for example a graph window from `plt.show()`). Increase `TIMEOUT`, or use `plt.savefig()` instead of `plt.show()` |
| A program is missing from the screenshots | Check it isn't in the `excluded` list and its folder name matches the rule |
| Text looks like a different font | The script uses Consolas/Courier on Windows. On macOS or Linux it falls back to a default font. Edit the font paths in the `load_font` function if you want a specific one |
| Characters look odd or boxes appear | Use a font that supports those characters, or avoid special symbols in the program output |
| Wrong inputs are used | The `INPUTS` key must match the file's folder and name, for example `Lab_5/perceptron.py` |

---

## Quick start (summary)

1. Download the project and extract it.
2. `pip install pillow`
3. In `automate_screenshots.py`, press **Ctrl + H** and replace `D:\pty\Python\Prassidha\AI_Lab` with your own folder path + replace the names inside lab_codes to your name(open the whole folder in vscode).
4. Run `python automate_screenshots.py`.
5. Open the `screenshots` folder inside your project. Done.
