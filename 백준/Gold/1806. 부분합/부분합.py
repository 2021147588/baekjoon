def solution(N, S, nums):

    start, end = 0, 0
    sum_ = nums[0]
    ans = 100001

    while True:
        if sum_ < S:
            end += 1
            if end == N: break
            sum_ += nums[end]
        else:
            sum_ -= nums[start]
            ans = min(ans, end - start + 1)
            start += 1
    if ans == 100001:
        ans = 0
    
    return ans       
        
if __name__=="__main__":
    s = input()
    N = int(s.split(' ')[0])
    S = int(s.split(' ')[1])
    n = input()
    nums = list(map(int, n.split(' ')))
    print(solution(N, S, nums))