from collections import deque
import sys
input = sys.stdin.readline

T = int(input())
for i in range(0, T):
    func = input()
    num = int(input())
    num_list = input().lstrip('[').rstrip(']\n').split(',')
    deq = deque(num_list)
    flag = 0
    rev = 0
    for j in range(0, len(func)):
        if func[j] == 'R':
            rev += 1
        elif func[j] == 'D':
            if deq and num != 0:
                if rev%2==1:
                    deq.pop()
                else:
                    deq.popleft()
            else:
                print("error")
                flag = 1
                break
    if flag == 0 and num != 0:
        if rev % 2 == 1:
            deq.reverse()
        print("[" + ",".join(deq)+"]")

    elif flag == 0 and num == 0:
        print("[]")
