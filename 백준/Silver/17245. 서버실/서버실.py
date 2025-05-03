

MAX=100
N = int(input())

freq = [0]*MAX

computers = []
max_lack = 0
for i in range(N):
    line = list(map(int, input().split()))
    computers+=line


left = 0
right = max(computers)
total = sum(computers)

answer = 0

def check_computers(m):

    over = 0
    for com in computers:
        if com < m:
            over +=com
        else:
            over += m

    return over
    
while left <= right:

    mid = (left+right)//2
    
    cnt = check_computers(mid)
    
    if cnt < total/2:
        left = mid + 1

    else:
        right = mid - 1
        answer = mid

        
print(answer)
