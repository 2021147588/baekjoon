import sys
from itertools import combinations

input = sys.stdin.readline

N = int(input())

board = [list(map(int, input().split())) for _ in range(N)]

row_col_sum = []

for i, j in zip(board, zip(*board)):
    row_col_sum.append(sum(i)+sum(j))

total_sum = sum(row_col_sum)//2

result = 100000000

for i in combinations(row_col_sum, N//2):
    result = min(abs(total_sum-sum(i)), result)

print(result)

