import sys

input = sys.stdin.readline


A, B = list(map(int, input().rstrip().split()))

answer = 1

while True:
    if B == A:
        print(answer)
        break
    if B == 1:
        print(-1)
        break
    
    if B % 2 == 0:
        B //=2
        
    elif B % 10 == 1:
        B //= 10
    else:
        print(-1)
        break
    # print(B)    
    answer+=1
