import sys

input = sys.stdin.readline

T = int(input())

MAX = 10001
# 계산
dp = [0]*MAX

dp[1] = 1
dp[2] = 2
dp[3] = 3
dp[4] = 4
dp[5] = 5

not_one = [0]*MAX

not_one[1] = 0
not_one[2] = 0
not_one[3] = 0
not_one[4] = 1
not_one[5] = 1

for i in range(6, MAX):
    not_one[i] = not_one[i-2]
    
    if i % 3 == 0:
        not_one[i]+=1
    

for i in range(6, MAX):
    
    dp[i] = dp[i-1] + not_one[i-2]
    if i % 3 == 0:
        dp[i]+=1

# print(dp)

for t in range(T):
    temp = int(input())

    print(dp[temp])
    
