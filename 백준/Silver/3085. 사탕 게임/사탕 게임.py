
N = int(input())

graph = [[0]*N for _ in range(N)]

for i in range(N):
    line = input()
    for j in range(N):
        graph[i][j] = line[j]


dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def switch(x, y, nx, ny):
    temp = graph[x][y]
    graph[x][y] = graph[nx][ny]
    graph[nx][ny] = temp

def check(x, y, nx, ny):

    longest = 0

    # 같은 열 확인
    # 위로
    d = 1
    i = x
    while i>0:
        if graph[i-1][y] == graph[i][y]:
            d+=1
            i-=1
            continue
        else:
            break
    # 아래로 
    i = x
    while i < N-1:
        if graph[i+1][y] == graph[i][y]:
            d+=1
            i+=1
            continue
        else:
            break
    longest = d

    # 같은 행 확인
    # 왼쪽으로
    d = 1
    j = y
    while j > 0:
        if graph[x][j-1] == graph[x][j]:
            d+=1
            j-=1
            continue
        else:
            break
    j = y
    while j < N-1:
        if graph[x][j+1] == graph[x][j]:
            d+=1
            j+=1
            continue
        else:
            break
    if longest < d:
        longest = d
    return longest


def solve(N):
    ans = 0
    for i in range(N):
        for j in range(N):
            for k in range(4):
                nx = i + dx[k]
                ny = j + dy[k]
                if nx < 0 or ny < 0 or nx >= N or ny >= N: continue
                switch(i, j, nx, ny)
                d = check(i, j, nx, ny)
                switch(i, j, nx, ny)
                if d > ans:
                    ans = d
                if ans == N:
                    return ans
    return ans
print(solve(N))            
