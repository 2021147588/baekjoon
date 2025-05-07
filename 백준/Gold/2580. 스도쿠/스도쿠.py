import sys
input = sys.stdin.readline
board = [list(map(int, input().split())) for _ in range(9)]

blank = []

for i in range(9):
    for j in range(9):
        if board[i][j] == 0:
            blank.append([i, j])


def check_row(i, k):
    for j in range(9):
        if board[i][j] == k:
            return False
    return True

def check_col(j, k):
    for i in range(9):
        if board[i][j] == k:
            return False
    return True

def check_square(x, y, k):

    start_x = x//3 * 3
    start_y = y//3 * 3

    for i in range(start_x, start_x+3):
        for j in range(start_y, start_y+3):
            if board[i][j] == k:
                return False
    return True

def dfs(n):
    if n == len(blank):
        for i in range(9):
            for j in range(9):
                print(board[i][j], end=' ')
            print()
        exit()
        return

    for k in range(1, 10):
        x = blank[n][0]
        y = blank[n][1]
        if check_row(x, k) and check_col(y, k) and check_square(x, y, k):
            board[x][y] = k
            dfs(n+1)
            board[x][y] = 0



dfs(0)
