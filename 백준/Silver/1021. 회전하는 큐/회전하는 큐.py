from collections import deque
import sys

input = sys.stdin.readline
#N: 큐의 크기, M: 뽑아내려하는 수의 개수
N, M = map(int, input().split())

num_list = list(map(int, input().split()))
deq = deque([i for i in range(1, N+1)])
cnt = 0
for i in num_list:
    index=0
    if deq[0]==i:
        deq.popleft()
        continue
        
    for j in range(0, len(deq)):
        if deq[j]==i:
            index = j
            break
    
    if index<=len(deq)//2:
        deq.rotate(0-index)
        cnt += index
    else:
        deq.rotate(len(deq)-index)
        cnt += (len(deq)-index)
    deq.popleft()


print(cnt)