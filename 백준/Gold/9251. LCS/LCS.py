a = input()
b = input()

LCS = [[0]*(len(b)+1) for _ in range(len(a)+1)]

longest = 0
N = len(a)+1
M = len(b)+1

for i in range(len(a)+1):
    for j in range(len(b)+1):
        if i == 0 or j == 0:
            LCS[i][j] = 0
        elif a[i-1] == b[j-1]:
            LCS[i][j] = LCS[i-1][j-1]+1
            if longest < LCS[i][j]:
                longest = LCS[i][j]
        else:
            LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1])


print(longest)
        
