# 17406.py
import copy
N, M, K = list(map(int, input().split(' ')))


A = [[0]*(M+1) for _ in range(N+1)]

for i in range(1, N+1):
    line = list(map(int, input().split(' ')))
    for j in range(1, M+1):
        A[i][j] = line[j-1]


def min_value(arr):
    min_v = 100000
    for i in range(1, N+1):
        a = sum(arr[i])
        if a < min_v:
            min_v = a
    return min_v


def permute(arr):
    result = [arr[:]]
    c = [0] * len(arr)
    i = 0
    while i < len(arr):
        if c[i] < i:
            if i % 2 == 0:
                arr[0], arr[i] = arr[i], arr[0]
            else:
                arr[c[i]], arr[i] = arr[i], arr[c[i]]
            result.append(arr[:])
            c[i] += 1
            i = 0
        else:
            c[i] = 0
            i += 1
    return result


cmd = []
for i in range(K):
    R, C, S = list(map(int, input().split(' ')))
    cmd.append([R, C, S])
    # rotate(R, C, S)

p_cmd = permute(cmd)
ans = 10000
for c in p_cmd:

    B = copy.deepcopy(A)
    # print("---Before B---")
    # for j in range(1, N+1):
    #     for k in range(1, M+1):
    #         print(B[j][k], end=' ')
    #     print()
    def rotate(r, c, s):
        start_x = r - s
        start_y = c - s
        end_x = r + s
        end_y = c + s

        while start_x < end_x and start_y < end_y:
            prev = B[start_x][start_y]
            # -->
            for j in range(start_y + 1, end_y + 1):
                curr = B[start_x][j]
                B[start_x][j] = prev
                prev = curr
            # 아래로
            for i in range(start_x + 1, end_x + 1):
                curr = B[i][end_y]
                B[i][end_y] = prev
                prev = curr
            for j in range(end_y - 1, start_y - 1, -1):
                curr = B[end_x][j]
                B[end_x][j] = prev
                prev = curr
            for i in range(end_x - 1, start_x - 1, -1):
                curr = B[i][start_y]
                B[i][start_y] = prev
                prev = curr
            start_x += 1
            start_y += 1
            end_x -= 1
            end_y -= 1


    for i in c:
        rotate(i[0], i[1], i[2])

    temp = min_value(B)
    if temp < ans:
        ans = temp
    # print("---After B---")
    # for j in range(1, N+1):
    #     for k in range(1, M+1):
    #         print(B[j][k], end=' ')
    #     print()
print(ans)