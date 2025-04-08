from itertools import combinations
N, M = list(map(int, input().split(' ')))

street = []


    
    
        
for _ in range(N):
    line = list(map(int, input().split(' ')))
    street.append(line)

chickens = []
house = []
for i in range(N):
    for j in range(N):
        if street[i][j]==2:
            chickens.append([i,j])
        elif street[i][j] == 1:
            house.append([i, j])

chickens_combs = list(map(list, combinations(chickens,M)))

distances = []
for comb in chickens_combs:
    d = 0
    for h in house:
        x = h[0]
        y = h[1]
        min_chick_d = 10000
        for chick in comb: 
            chick_x = chick[0]
            chick_y = chick[1]
            chick_d = abs(chick_x-x)+abs(chick_y-y)
            if min_chick_d > chick_d:
                min_chick_d = chick_d
        d += min_chick_d
    distances.append(d)
print(min(distances))