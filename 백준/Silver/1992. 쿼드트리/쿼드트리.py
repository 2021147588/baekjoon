
def compress(x0, y0, depth, length, map):
    if length == 1:
        print(map[x0][y0], end='')
        return
        
    color = map[x0][y0]
    next = 0
    for i in range(x0, x0+length):
        for j in range(y0, y0+length):
            if color != map[i][j]:
                next = 1
                break
            
    if next==1:
        print("(", end='')
        compress(x0, y0, depth+1, length//2, map)
        compress(x0, y0+length//2, depth+1, length//2, map)
        compress(x0+length//2, y0, depth+1, length//2, map)
        compress(x0+length//2, y0+length//2, depth+1, length//2, map)
        print(")", end='')
    else:
        print(color, end='')
 

def solution(N, map):
    compress(0,0,1, N, map)
      

if __name__=="__main__":
    N = int(input())
    i_map = [[0]*N for _ in range(N)]
    for i in range(N):
        l = input()
        for j in range(N):
            i_map[i][j] = int(l[j])
    solution(N, i_map)   
