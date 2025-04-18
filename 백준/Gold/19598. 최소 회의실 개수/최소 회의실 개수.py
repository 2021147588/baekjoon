import sys
import heapq

input = sys.stdin.readline

N = int(input().rstrip())

meetings = []

heapq.heapify(meetings)


for i in range(N):
    start, end = list(map(int, input().rstrip().split()))

    meetings.append((start, end))

meetings.sort()
last_time = 0
answer = 1
times = []

for start, end in meetings:

    if times and times[0] <= start:
        heapq.heappop(times)

    heapq.heappush(times, end)
        
    
print(len(times))
        
