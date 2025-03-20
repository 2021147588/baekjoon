from collections import Counter
def solution(N, K, A):
    
    end = 0
    ans = 0
    start = 0
    d = { i: 0 for i in A}
    while end < N and start < N:
        # print(start, end)
        # print(d)
        if d[A[end]] < K:
            d[A[end]]+=1
            if end-start+1 > ans:
                ans = end-start+1
            end+=1
        else:
            d[A[start]]-=1
            start += 1
    return ans
    

if __name__ == "__main__":
    l1 = input()
    N, K = tuple(map(int, l1.split(' ')))
    
    l2 = input()
    A = list(map(int, l2.split(' ')))

    print(solution(N, K, A))