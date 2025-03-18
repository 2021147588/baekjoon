from collections import Counter

def solution(genres, plays):
    g_dict = {}
    g_count = {}
    n = len(genres)
    
    for i in range(n):
        g = genres[i]
        if g not in g_dict.keys():
            g_dict[g] = []
            g_count[g] = 0
        
        g_dict[g].append([plays[i], i])
        g_count[g] += plays[i]
    
    g_count = dict(sorted(g_count.items(), key=lambda x: x[1], reverse=True))
    
    answer = []
    for key,_ in g_count.items():
        a = g_dict[key]
        a = sorted(a, key=lambda x: (-x[0], x[1]))
        for i in range(min(2, len(a))):  # 곡이 2개보다 적을 경우를 대비
            answer.append(a[i][1])
            

        
    return answer