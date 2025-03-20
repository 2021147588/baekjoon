
left = 'qwertasdfgzxcv'
right = 'yuiophjklbnm'

first_line = 'qwertyuiop'
second_line = 'asdfghjkl'
third_line = 'zxcvbnm'
d = {}
for i in range(len(first_line)):
    d[first_line[i]] = [0, i]
for i in range(len(second_line)):
    d[second_line[i]] = [1, i]
for i in range(len(third_line)):
    d[third_line[i]] = [2, i]   

def cal_distance(pos_x,pos_y , curr_x, curr_y):
    distance = abs(curr_x-pos_x)+abs(curr_y-pos_y)
    return distance    
    
def solution(s_l, s_r, words):
   
    curr_left_x,curr_left_y  = d[s_l]
    curr_right_x, curr_right_y = d[s_r]
    time = 0
    for w in words:
        pos_x, pos_y = d[w]
        if w in left:
            time += 1+cal_distance(pos_x,pos_y, curr_left_x, curr_left_y)
            curr_left_x = pos_x
            curr_left_y = pos_y
        else:
            time += 1 + cal_distance(pos_x,pos_y, curr_right_x, curr_right_y)               
            curr_right_x = pos_x
            curr_right_y = pos_y

    return time

if __name__=="__main__":
    s_l,s_r = tuple(input().split(' '))
    words = input()
    
    print(solution(s_l, s_r, words))