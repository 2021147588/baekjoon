# def solution(numbers, target):
#     answer = 0
    
#     cnt = len(numbers)
#     ss = []
#     for i in range(cnt+1):
#         ss.append(1<<i)
    
#     on_index = []
#     on = range(0,cnt)
#     for i in range(1<<cnt):
#         subsets = []
#         for s, n in zip(ss, on):
#             if s&i:
#                 subsets.append(n)
#         on_index.append(subsets)
#     # print(on_index)
#     total_idx_set = set(on)
#     for idxs in on_index:
#         total = 0
#         idxs_set = set(idxs)
#         not_sum_set = list(total_idx_set - idxs_set)
        
#         for idx in idxs:
#             total+=numbers[idx]
#         for not_sum_idx in not_sum_set:
#             total-=numbers[not_sum_idx]
        
#         if target == total:
#             answer+=1
            
#     return answer

answer = 0
def dfs(idx, numbers, target, value):
    global answer
    
    if target == value and idx== len(numbers):
        answer+=1
        return
    
    if idx == len(numbers):
        return 
    
    dfs(idx+1, numbers, target, value+numbers[idx])
    dfs(idx+1, numbers, target, value-numbers[idx])
    
def solution(numbers, target):
    global answer
    dfs(0, numbers, target, 0)
    return answer