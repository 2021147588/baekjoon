

N = int(input())

K = int(input())

sensor = list(map(int, input().split()))

sensor.sort()
diffs = []
for i in range(N-1):
    diffs.append(sensor[i+1]-sensor[i])

diffs.sort(reverse=True)
print(sum(diffs[K-1:]))
