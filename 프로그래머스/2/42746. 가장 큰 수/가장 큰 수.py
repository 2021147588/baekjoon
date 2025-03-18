def solution(numbers):
#     answer = ''
#     answer = sorted(list(map(str, numbers)), reverse=True)
    
#     temp = ''
#     index = 0
#     for i in range(len(answer)):
#         flag = True
#         cur = i
#         if len(answer[cur])==1:
#             while flag==True and cur>0:
#                 for j in answer[cur-1]:
#                     if j > answer[cur]:
#                         flag=False
#                 if flag==True:
#                     t = answer[cur-1]
#                     answer[cur-1] = answer[cur]
#                     answer[cur] = t
#                     cur -= 1
#     answer = ''.join(answer)
        #0. key point
    numbers_str = [str(num) for num in numbers]                 #1. 사전 값으로 정렬하기
    numbers_str.sort(key=lambda num: num*3, reverse=True)       #2. number는 1000이하의 숫자이므로 x3(반복)한 값으로 비교

    return str(int(''.join(numbers_str)))
        
    return answer