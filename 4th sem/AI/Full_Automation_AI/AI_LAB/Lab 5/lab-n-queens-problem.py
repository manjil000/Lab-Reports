# Lab: n-Queens Problem
# Program by: [Your Name]
# Roll no: [Your Roll No]

# Step 1: Check if placing a queen is safe
def is_safe(board, row, col, n):
    # Check same row on left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    i = row
    j = col

    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False

        i = i - 1
        j = j - 1

    # Check lower diagonal on left side
    i = row
    j = col

    while i < n and j >= 0:
        if board[i][j] == 1:
            return False

        i = i + 1
        j = j - 1

    return True


# Step 2: Solve n-Queens using backtracking
def solve_n_queens(board, col, n):
    # If all queens are placed
    if col >= n:
        return True

    # Try placing queen in each row of this column
    for row in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 1

            # Recur to place rest of the queens
            if solve_n_queens(board, col + 1, n):
                return True

            # Backtrack
            board[row][col] = 0

    return False


# Step 3: Print the board
def print_board(board, n):
    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                print("♛", end=" ")
            else:
                print("·", end=" ")

        print()

    print()


# Step 4: Count all solutions
def count_solutions(board, col, n):
    if col >= n:
        return 1

    count = 0

    for row in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 1
            count = count + count_solutions(board, col + 1, n)
            board[row][col] = 0

    return count


# Step 5: Find all solutions
def find_all_solutions(board, col, n, solutions):
    if col >= n:
        # Store a copy of the solution
        solution = []

        for i in range(n):
            row_solution = []

            for j in range(n):
                row_solution.append(board[i][j])

            solution.append(row_solution)

        solutions.append(solution)
        return

    for row in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 1
            find_all_solutions(board, col + 1, n, solutions)
            board[row][col] = 0


# Step 6: Main program
def n_queens(n):
    print("=" * 50)
    print(f"{n}-QUEENS PROBLEM")
    print("=" * 50)
    print()

    # Find one solution
    board = [[0 for _ in range(n)] for _ in range(n)]

    print(f"Finding one solution for {n}-Queens...")
    print()

    if solve_n_queens(board, 0, n):
        print(f"Solution found for {n}-Queens:")
        print_board(board, n)
    else:
        print(f"No solution exists for {n}-Queens")
        return

    # Count all solutions
    board = [[0 for _ in range(n)] for _ in range(n)]

    total_solutions = count_solutions(board, 0, n)

    print(f"Total solutions for {n}-Queens: {total_solutions}")
    print()

    # Find all solutions (limit to 5 for display)
    if n <= 6:
        board = [[0 for _ in range(n)] for _ in range(n)]
        solutions = []

        find_all_solutions(board, 0, n, solutions)

        print(f"All {len(solutions)} solutions for {n}-Queens:")

        for i, sol in enumerate(solutions):
            print(f"Solution {i+1}:")

            for row in sol:
                for val in row:
                    if val == 1:
                        print("♛", end=" ")
                    else:
                        print("·", end=" ")

                print()

            print()

    else:
        print(f"Showing first 3 solutions for {n}-Queens:")

        board = [[0 for _ in range(n)] for _ in range(n)]
        solutions = []

        find_all_solutions(board, 0, n, solutions)

        for i in range(min(3, len(solutions))):
            print(f"Solution {i+1}:")

            for row in solutions[i]:
                for val in row:
                    if val == 1:
                        print("♛", end=" ")
                    else:
                        print("·", end=" ")

                print()

            print()


# Step 7: Test for different n values
n_queens(4)
n_queens(8)