from collections import deque

INF = 1000

N = int(input())

ans = [[0]*N for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

graph = [[0]*N for _ in range(N)]

def bfs(start):
    q = deque([start])
    
    visited = [0]*N

    while len(q)!=0:
        node = q.popleft()

        for i in range(N):
            if graph[node][i] == 0: continue
            if visited[i] == 1: continue
            ans[start][i] = 1
            visited[i] = 1
            q.append(i)
            

    


for i in range(N):
    line = list(map(int, input().split()))
    
    for j in range(N):
        graph[i][j] = line[j]


for i in range(N):
    bfs(i)

for i in range(N):
    for j in range(N):
        print(ans[i][j], end=' ')
    print()
