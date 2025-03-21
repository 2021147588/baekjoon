def solution(N, K, A):
    
    answer = 0
    
    start = 0
    end = 0
    f = {i: 0 for i in A}

    while end < N and start < N:
        
        if f[A[end]] <K:
            f[A[end]] += 1
            end+=1
            if answer < end-start:
                answer = end-start
        else:
            f[A[start]]-=1
            start+=1
            
    return answer


if __name__ == "__main__":
    l1 = input()
    N, K = tuple(map(int, l1.split(' ')))
    
    l2 = input()
    A = list(map(int, l2.split(' ')))

    print(solution(N, K, A))