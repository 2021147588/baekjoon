def solution(edges):
    answer = []
    graph = {}
    add_node = 0
    eight_graph = 0
    bar_graph=0
    dought_graph = 0
    for edge in edges:
        s = edge[0]
        e = edge[1]
        
        # 들어오는 노드 개수 세기
        if s not in graph.keys():
            graph[s] = [0, 0]
        graph[s][0] += 1
        
        # 나가는 노드 개수 세기
        if e not in graph.keys():
            graph[e] = [0, 0]
        graph[e][1] += 1 
    
    for k, v in graph.items():
        if v[0] >= 2 and v[1] == 0:
            add_node = k
        elif v[0] == 2 and v[1] >= 2:
            eight_graph +=1
        elif v[0] == 0 and v[1] >= 1:
            bar_graph+=1
            
    dought_graph = graph[add_node][0]-(eight_graph+bar_graph)
    answer.append(add_node)
    answer.append(dought_graph)
    answer.append(bar_graph)
    answer.append(eight_graph)
    return answer