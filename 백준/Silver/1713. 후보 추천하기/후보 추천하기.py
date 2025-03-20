def solution(N, total, students):
    
    d = {}
    for i in range(total):
        if len(d.keys()) < N:
            if students[i] not in d.keys():
                d[students[i]] = [1, i]
            else:
                d[students[i]][0]+=1
        else:
            if students[i] not in d.keys():
                
                l = sorted(d, key=lambda x: (d[x][0], d[x][1]),reverse=True)
                del d[l[-1]]
                d[students[i]] = [1, i]
            else:
                d[students[i]][0]+=1
        # print(d)
    print(' '.join(list(map(str, sorted(list(d.keys()))))))      
    
if __name__=="__main__":
    N = int(input())
    total = int(input())
    students = list(map(int, input().split(' ')))
    
    solution(N, total, students)