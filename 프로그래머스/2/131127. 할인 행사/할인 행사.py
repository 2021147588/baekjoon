from collections import defaultdict, Counter

def solution(want, number, discount):
    answer = 0
    
    db = defaultdict(str)
    for i, w in enumerate(want):
        db[w] = number[i]
    flag = False
    for i in range(len(discount)):
        if i < len(discount)-9:
            d = Counter(discount[i:i+10])
        else:
            d = Counter(discount[i:])
            
        flag = 0
        
        for k, v in db.items():
            if d[k] != db[k]:
                flag = 0
                break
            else:
                flag +=1
        
        if flag == len(db.keys()):
            answer +=1
            
                
    return answer