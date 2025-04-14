from collections import defaultdict
import sys
input = sys.stdin.readline

N, M = list(map(int, input().rstrip().split()))

db = defaultdict(str)


for i in range(N):
    site, pwd = list(map(str, input().split()))
    db[site] = pwd

for i in range(M):
    site = input().rstrip()
    sys.stdout.write(db[site]+'\n')
