dx = [-1, 1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, -1, 1, 1,-1, -1, 1 ]
map = [[0]*20 for _ in range(20)]

# if dir == 0: 좌우
# if dir == 2: 상하
# if dir ==  4: 우상향
# if dir == 6: 우하향
def bfs(start_x, start_y, bw, dir):
    queue = []
    visited = [[0]*20 for _ in range(20)]
    queue.append([start_x, start_y])
    visited[start_x][start_y] = 0
    cnt = 1
    while len(queue) != 0:
        x = queue[0][0]
        y = queue[0][1]
        del queue[0]
        
        for i in range(dir, dir+2):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx <= 0 or nx >= 20 or ny <=0 or ny >= 20: continue
            
            if visited[nx][ny] == 0 and map[nx][ny] == bw:
                visited[nx][ny] = 1
                cnt+=1
                queue.append([nx, ny])
    if cnt == 6:
    
        return True
    else:          
        return False    
                 
        

def solution(n, order):
    for i in range(0, n):
        x = order[i][0]
        y = order[i][1]
        if (i+1)%2 == 0:
            color = 2
        else:
            color = 1
        map[x][y] = color
        
        a = bfs(x, y, color, 0)
        b = bfs(x, y, color, 2)
        c = bfs(x, y, color, 4)
        d = bfs(x, y, color, 6)
        
        if a or b or c or d:            
            return i+1
    
    return -1
    
if __name__ == "__main__":
    n = int(input())
    order = []
    for i in range(n):
        x, y = input().split(' ')
        order.append([int(x), int(y)])
    
    print(solution(n, order))