T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # ///////////////////////////////////////////////////////////////////////////////////
    
    N = int(input())
    a = input()
    b = input()
    A = list(map(int, a.split(' ')))
    B = list(map(int, b.split(' ')))
    teams = {}
    while len(A) != 0 and len(B) != 0:
            while len(A)!= 0 and A[0] in teams.keys():
                del A[0]
            if len(A) > 0: 
                teams[A[0]] = 'A'
                del A[0] 
            while len(B)!=0 and B[0] in teams.keys():
                del B[0]
            if len(B) > 0: 
                teams[B[0]] = 'B'
                del B[0]
        
    for i in range(N):
        print(teams[i+1], end='')
    print()
    # ///////////////////////////////////////////////////////////////////////////////////
