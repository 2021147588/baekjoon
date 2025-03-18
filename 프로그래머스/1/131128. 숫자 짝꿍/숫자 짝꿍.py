def solution(X, Y):
    answer = ''
    x = set(X)
    y = set(Y)
    inter = x & y
    if len(inter) == 0:
        return "-1"
    
    c_x = {i: 0 for i in X if i in inter}
    c_y = {i: 0 for i in Y if i in inter}
            
    for i in X:
        if i in inter:
            c_x[i]+=1
    
    for i in Y:
        if i in inter:
            c_y[i]+=1
            
    inter = list(inter)
    if len(inter)==1 and inter[0]=='0':
        return "0"
        
    

    for i in inter:
        if c_x[i] < c_y[i]:
            answer = answer + c_x[i]*i
        else:
            answer = answer + c_y[i]*i
    
    answer = ''.join(sorted(answer, reverse=True))
    
        
        
    return answer