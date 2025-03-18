def solution(X, Y):
    answer = ''
    n = "0123456789"
    
    for i in n:
        answer += i*min(X.count(i), Y.count(i))
    
    if len(answer) == 0:
        return "-1"
    elif len(answer)==answer.count("0"):
        return "0"
    else:
        answer = ''.join(sorted(answer, reverse=True))

    
    return answer