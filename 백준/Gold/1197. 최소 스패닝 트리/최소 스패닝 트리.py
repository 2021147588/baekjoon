import heapq

def solution(V, E, G):
    graph = [[] for _ in range(V+1)]
    visited = [0]*(V+1)
    
    for g in G:
        start, end, d = list(map(int, g.split(' ')))
        
        graph[start].append([end, d])
        graph[end].append([start, d])
    
    heap = [[0, 1]] # 거리, node이름 
    heapq.heapify(heap)
    cost = 0
    cnt = 0
    while cnt < V:
        k, v = heapq.heappop(heap)
        if visited[v]: continue
        visited[v] = 1
        cost += k
        cnt +=1
        for n in graph[v]:
            heapq.heappush(heap, [n[1], n[0]])
        
    # print(cost)
    return cost
    
if __name__=="__main__":
    
    V, E = list(map(int, input().split(' ')))
    G = []
    for e in range(E):
        a = input()
        G.append(a)
    print(solution(V, E, G))