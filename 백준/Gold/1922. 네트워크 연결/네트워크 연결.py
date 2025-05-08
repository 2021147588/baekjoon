import heapq


N = int(input())

M = int(input())

graph = [[] for _ in range(N+1)]

for i in range(M):

    start, end, cost = list(map(int, input().split()))

    graph[start].append([end, cost])

    graph[end].append([start, cost])

def prim():
    
    heap = []

    heapq.heappush(heap, (0, start))
    visited = [0]*(N+1)
    total_cost = 0

    for i in range(1, N+1):
        while heap and visited[heap[0][1]]:
            heapq.heappop(heap)
        
        weight, node = heapq.heappop(heap)

        total_cost += weight

        visited[node] = 1

        for adj, w in graph[node]:
            if visited[adj] == 0:
                heapq.heappush(heap, (w, adj))

                
    return total_cost
            
print(prim())   
