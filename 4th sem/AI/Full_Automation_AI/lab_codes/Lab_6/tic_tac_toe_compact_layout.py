import os

board = [' ' for _ in range(9)]

LEFT_COL = 2
RIGHT_COL = 40

def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")

def print_at(row, col, text=""):
    print(f"\033[{row};{col}H{text}", end="", flush=True)

def print_board_at(board, row, col):
    print_at(row, col,     f" {board[0]} | {board[1]} | {board[2]} ")
    print_at(row+1, col,   "---+---+---")
    print_at(row+2, col,   f" {board[3]} | {board[4]} | {board[5]} ")
    print_at(row+3, col,   "---+---+---")
    print_at(row+4, col,   f" {board[6]} | {board[7]} | {board[8]} ")

def print_number_board(row, col):
    print_at(row, col,     " 1 | 2 | 3 ")
    print_at(row+1, col,   "---+---+---")
    print_at(row+2, col,   " 4 | 5 | 6 ")
    print_at(row+3, col,   "---+---+---")
    print_at(row+4, col,   " 7 | 8 | 9 ")

def is_winner(board, player):
    wins = [
        [0,1,2], [3,4,5], [6,7,8],
        [0,3,6], [1,4,7], [2,5,8],
        [0,4,8], [2,4,6]
    ]
    return any(all(board[i] == player for i in combo) for combo in wins)

def is_draw(board):
    return ' ' not in board

def game_over(board):
    return is_winner(board, 'X') or is_winner(board, 'O') or is_draw(board)

def minimax(board, is_maximizing):
    if is_winner(board, 'X'):
        return 1
    if is_winner(board, 'O'):
        return -1
    if is_draw(board):
        return 0

    if is_maximizing:
        best = -999999
        for i in range(9):
            if board[i] == ' ':
                board[i] = 'X'
                value = minimax(board, False)
                board[i] = ' '
                best = max(best, value)
        return best

    best = 999999
    for i in range(9):
        if board[i] == ' ':
            board[i] = 'O'
            value = minimax(board, True)
            board[i] = ' '
            best = min(best, value)
    return best

def ai_move(board):
    best_value = -999999
    best_move = -1

    for i in range(9):
        if board[i] == ' ':
            board[i] = 'X'
            value = minimax(board, False)
            board[i] = ' '

            if value > best_value:
                best_value = value
                best_move = i

    board[best_move] = 'X'
    return best_move

def human_move(board):
    while True:
        try:
            print_at(15, RIGHT_COL, "Your move (1-9): ")
            print(f"\033[15;{RIGHT_COL + 17}H", end="", flush=True)
            move = int(input()) - 1

            if not 0 <= move <= 8:
                print_at(16, RIGHT_COL, "Invalid! Enter 1-9.")
            elif board[move] != ' ':
                print_at(16, RIGHT_COL, "Cell already taken!")
            else:
                board[move] = 'O'
                return
        except ValueError:
            print_at(16, RIGHT_COL, "Invalid! Enter a number.")

def play_game():
    clear_screen()

    print_at(1, LEFT_COL, "TIC-TAC-TOE (X = AI, O = Human)")
    print_at(2, LEFT_COL, "=" * 35)

    print_at(4, LEFT_COL, "You are O. AI is X.")
    print_at(5, LEFT_COL, "Position numbers:")

    print_number_board(7, LEFT_COL)

    print_at(7, RIGHT_COL, "CURRENT BOARD")
    print_board_at(board, 8, RIGHT_COL)

    while not game_over(board):
        print_at(15, RIGHT_COL, "AI is thinking...")
        ai_move(board)
        print_board_at(board, 18, RIGHT_COL)

        if game_over(board):
            break

        print_at(15, RIGHT_COL, "Your turn.")
        human_move(board)
        print_board_at(board, 18, RIGHT_COL)

    print_at(25, LEFT_COL, "FINAL RESULT")
    print_at(26, LEFT_COL, "-" * 35)
    print_board_at(board, 27, LEFT_COL)

    if is_winner(board, 'X'):
        result = "AI wins! Better luck next time."
    elif is_winner(board, 'O'):
        result = "You win! Congratulations!"
    else:
        result = "It's a draw! Good game!"

    print_at(27, RIGHT_COL, result)
    print_at(32, 1, "")

play_game()
