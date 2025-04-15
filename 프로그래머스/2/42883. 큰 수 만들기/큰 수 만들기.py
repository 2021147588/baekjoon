def solution(number, k):
    answer = ''
    stack = []
    
    stack.append(number[0])
    for i in range(1, len(number)):
        while len(stack)!=0 and k > 0 and int(stack[-1]) < int(number[i]):
            stack.pop()
            k-=1
        stack.append(number[i])
    answer = ''.join(stack)
    
    if k!=0:
        answer = answer[:-k]
    return answer