import heapq


N, M, K, X = list(map(int, input().split()))

graph = [[] for _ in range(N+1)]

INF = 2000001

def dijikstra(start):

    shortest_distance = [INF]*(N+1)
    
    heap = []
    shortest_distance[start] = 0
    heapq.heappush(heap, [0, start])

    while heap:
        dist, node = heapq.heappop(heap)

        if dist > shortest_distance[node]:
            continue

        for adj in graph[node]:
            D = dist + 1
            if D < shortest_distance[adj]:
                shortest_distance[adj] = D
                heapq.heappush(heap, [dist+1, adj])
                    
    
    return shortest_distance

for i in range(M):

    s, e = list(map(int,input().split()))

    graph[s].append(e)

w = dijikstra(X)
flag = False
for i, d in enumerate(w):
    if d == K:
        print(i)
        flag = True
    
if flag == False:
    print(-1)

        
