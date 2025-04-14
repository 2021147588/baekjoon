from collections import defaultdict
import sys

input = sys.stdin.readline
print = sys.stdout.write
N = int(input().rstrip())

db = set()

for i in range(N):
    name, in_out = list(map(str, input().rstrip().split()))
    if in_out == 'enter':
        db.add(name)
    elif in_out == 'leave':
        db.remove(name)

names = sorted(list(db), reverse=True)

for name in names:
    print(name+'\n')
