# Lab: Maze Solver (BFS & DFS)
# Program by: [Your Name]
# Roll no: [Your Roll No]

from collections import deque

# Step 1: Define the maze
maze = [
    ['S', 0, 0, 1, 0],
    [1, 1, 0, 1, 0],
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 'G']
]

# Find start and goal positions
def find_positions(maze):
    start = None
    goal = None

    for i in range(len(maze)):
        for j in range(len(maze[0])):
            if maze[i][j] == 'S':
                start = (i, j)
            elif maze[i][j] == 'G':
                goal = (i, j)

    return start, goal


# Step 2: Get valid neighbors
def get_neighbors(maze, pos, visited):
    rows = len(maze)
    cols = len(maze[0])
    r, c = pos
    neighbors = []

    # Up, Down, Left, Right
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    for dr, dc in directions:
        nr, nc = r + dr, c + dc

        if 0 <= nr < rows and 0 <= nc < cols:
            if (nr, nc) not in visited:
                if maze[nr][nc] != 1:  # Not a wall
                    neighbors.append((nr, nc))

    return neighbors


# Step 3: BFS Solver
def bfs_solver(maze):
    start, goal = find_positions(maze)

    if not start or not goal:
        return None, "Start or goal not found!"

    queue = deque([(start, [start])])
    visited = set([start])
    nodes_expanded = 0

    while queue:
        current, path = queue.popleft()
        nodes_expanded += 1

        if current == goal:
            return path, nodes_expanded

        for neighbor in get_neighbors(maze, current, visited):
            visited.add(neighbor)
            queue.append((neighbor, path + [neighbor]))

    return None, nodes_expanded


# Step 4: DFS Solver (Iterative)
def dfs_solver(maze):
    start, goal = find_positions(maze)

    if not start or not goal:
        return None, "Start or goal not found!"

    stack = [(start, [start])]
    visited = set([start])
    nodes_expanded = 0

    while stack:
        current, path = stack.pop()
        nodes_expanded += 1

        if current == goal:
            return path, nodes_expanded

        for neighbor in get_neighbors(maze, current, visited):
            visited.add(neighbor)
            stack.append((neighbor, path + [neighbor]))

    return None, nodes_expanded


# Step 5: Print the maze with path
def print_maze_with_path(maze, path):
    if not path:
        print("No path found!")
        return

    # Create a copy of the maze
    maze_copy = []

    for row in maze:
        maze_copy.append(row[:])

    # Mark the path
    for r, c in path:
        if maze_copy[r][c] != 'S' and maze_copy[r][c] != 'G':
            maze_copy[r][c] = '*'

    # Print the maze
    print("Maze with Path (* = path):")

    for row in maze_copy:
        line = ""

        for cell in row:
            if cell == 1:
                line += "█ "
            elif cell == 0:
                line += "· "
            elif cell == '*':
                line += "★ "
            else:
                line += str(cell) + " "

        print(line)

    print()


# Step 6: Main function
def solve_maze(maze):
    print("=" * 60)
    print("MAZE SOLVER")
    print("=" * 60)
    print()

    print("Original Maze:")

    for row in maze:
        line = ""

        for cell in row:
            if cell == 1:
                line += "█ "
            elif cell == 0:
                line += "· "
            else:
                line += str(cell) + " "

        print(line)

    print()

    print("-" * 60)
    print("BFS SEARCH")
    print("-" * 60)

    path, nodes = bfs_solver(maze)

    if path:
        print(f"Path found! Steps: {len(path)-1}, Nodes expanded: {nodes}")
        print(f"Path: {' → '.join([str(p) for p in path])}")
        print()
        print_maze_with_path(maze, path)
    else:
        print(f"No path found! Nodes expanded: {nodes}")

    print("-" * 60)
    print("DFS SEARCH")
    print("-" * 60)

    path, nodes = dfs_solver(maze)

    if path:
        print(f"Path found! Steps: {len(path)-1}, Nodes expanded: {nodes}")
        print(f"Path: {' → '.join([str(p) for p in path])}")
        print()
        print_maze_with_path(maze, path)
    else:
        print(f"No path found! Nodes expanded: {nodes}")


# Step 7: Run the solver
solve_maze(maze)