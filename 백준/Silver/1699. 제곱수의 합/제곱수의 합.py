import math

N = int(input())

dp = [x for x in range(N+1)]


for i in range(4, N+1):
    
    M = int(math.sqrt(i))
    # print("M", M)
    for j in range(1, M+1):
        # print(i)
        # print(i-j*j)
        if dp[i] > dp[i-j*j]+1:
            dp[i] = dp[i-j*j]+1
print(dp[-1])
    
