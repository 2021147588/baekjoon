def update_pop(unions, maps):
    
    for union in unions:
        n = len(union[:-1])
        total = union[-1]
        pop = int(total/n)

        for u in range(n):
            maps[union[u][0]][union[u][1]] = pop
    return maps

def check_diff(maps, N, L, R):
    dxx = [0, 0, 1] 
    dyy = [0, 1, 0]
    pos = []
    for i in range(N):
        for j in range(N):
            for k in range(3):
                nx = i + dxx[k]
                ny = j + dyy[k]
                if nx < 0 or ny < 0 or nx >= N or ny >=N: continue

                diff = abs(maps[nx][ny]-maps[i][j])
                if diff >= L and diff <= R:
                    pos.append([nx,ny])
    return pos    
            
            
def solution(N, L, R, maps):
    
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    day = 0
    while len(check_diff(maps, N, L, R))!=0:
        pos = check_diff(maps, N, L, R) 
        day +=1
        visited = [[0]*N for _ in range(N)]
        queue = []
        unions = []
        # for i in range(N):
        #     for j in range(N):
        # print("p", pos)
        for p in pos:
            i = p[0]
            j = p[1]
            if visited[i][j]==0:
                queue.append([i, j])
                visited[i][j]=1
                union = []
                union.append([i, j])
                total_pop = maps[i][j]
                while len(queue) > 0:
                    x = queue[0][0]
                    y = queue[0][1]
                    del queue[0]
                    for k in range(4):
                        nx = x + dx[k]
                        ny = y + dy[k]
                        if nx < 0 or ny < 0 or nx >= N or ny >=N: continue
                        diff = abs(maps[nx][ny]-maps[x][y])
                        if visited[nx][ny]==0 and diff >= L and diff <= R:

                            queue.append([nx, ny])
                            visited[nx][ny] = 1
                            union.append([nx, ny])
                            total_pop += maps[nx][ny]

                union.append(total_pop)
                unions.append(union)
                maps =update_pop(unions, maps)
        # print(f"---{day} maps---")
        # print(maps)
    return day
    

if __name__=='__main__':
    N, L, R = list(map(int, input().split(' ')))
    maps = [[0]*N for _ in range(N)]
    
    for i in range(N):
        a = list(map(int, input().split(' ')))
        for j in range(len(a)):
            maps[i][j]=a[j]

    print(solution(N, L, R, maps))