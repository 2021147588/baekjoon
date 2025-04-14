from collections import deque, defaultdict
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

N, M = list(map(int, input().split()))

graph = [[0]*M for _ in range(N)]

for i in range(N):
    line = list(map(int, input().split()))
    for j in range(M):
        graph[i][j] = line[j]

answers = defaultdict(int)

def bfs(start_x, start_y):
    longest_d = 0
    pwd = 0
    q = deque([([start_x, start_y], 0)])

    visited = [[0]*M for _ in range(N)]
    longest_paths = []
    visited[start_x][start_y] = 1


    # 자기자신이 아닐때
    while len(q)!=0:
        pos, d = q.popleft()
        x = pos[0]
        y = pos[1]
        flag = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            if visited[nx][ny]== 0 and graph[nx][ny] != 0:
                q.append(([nx, ny], d+1))
                flag = False
                visited[nx][ny] = 1
                if longest_d <= d+1:
                    longest_d = d+1
                    longest_paths.append([[nx, ny], d+1])
        if flag:
            pwd = graph[start_x][start_y] + graph[x][y]
            if answers[d] < pwd:
                answers[d] = pwd
    

for i in range(N):
    for j in range(M):
        if graph[i][j] != 0:
            bfs(i, j)

a = sorted(answers)
print(answers[a[-1]])
