N = int(input())

left = 0
right = N

while left<=right:
    mid = (left+right)//2

    if mid**2 < N:
        left = mid + 1
    else:
        right = mid - 1

print(left)
        

    
