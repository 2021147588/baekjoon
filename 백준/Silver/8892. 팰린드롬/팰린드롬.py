from itertools import permutations

T = int(input())

def perlindrom(pwd):

    n = len(pwd)//2
    flag = True
    for i in range(n):
        if pwd[i] != pwd[-i-1]:
            flag = False

    return flag


for t in range(T):
    N = int(input())

    words = []
    for i in range(N):
        line = input()
        
        words.append(line)

    per = list(permutations(words, 2))
    f = False
    for i in range(len(per)):
        p = ''.join(per[i])
        if perlindrom(p):
            f = True
            print(p)
            break
    if f == False:
        print(0)    
