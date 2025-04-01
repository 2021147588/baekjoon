T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    V, E, a, b = list(map(int, input().split(' ')))
    trees = [[] for _ in range(V+1)]
    nodes = list(map(int, input().split(' ')))
    for i in range(E):
        trees[nodes[2*i]].append(nodes[2*i+1])
    
    def find_target(target):
        parents = set()
        distance = {}
        d = 0
        while target != 1:
            for i in range(1, V+1):
                if target in trees[i]:
                    parents.add(i)
                    d+=1
                    distance[i] = d
                    target = i
                    break
            
        return parents, distance
    a_parents, a_distance = find_target(a)  
    b_parents, b_distance = find_target(b)
    common_list = sorted(list(a_parents & b_parents))
    min_d = 100000
    common = 0
    for c in common_list:
        d = a_distance[c] + b_distance[c]
        if min_d > d:
            min_d = d
            common = c
            
    
    answer = len(trees[common])
    queue = []
    queue.extend(trees[common])
    while len(queue)!=0:
        p = queue[0]
        answer += len(trees[p])
        del queue[0]
        queue.extend(trees[p])
    print("#"+str(test_case)+" "+str(common)+" "+str(answer+1))
    