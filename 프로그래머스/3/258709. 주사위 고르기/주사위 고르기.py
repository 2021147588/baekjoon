import bisect
from itertools import product, combinations

def solution(dice):
    N = len(dice)
    answer = []
    max_win_rate = 0

    # A 팀 조합들
    A_dice_list = list(combinations(range(N), N // 2))
    
    for A_indices in A_dice_list:
        B_indices = [i for i in range(N) if i not in A_indices]
        
        A_dice = [dice[i] for i in A_indices]
        B_dice = [dice[i] for i in B_indices]

        # A와 B 가능한 모든 점수의 합
        A_scores = list(map(sum, product(*A_dice)))
        B_scores = list(map(sum, product(*B_dice)))

        # B 점수 정렬 후, A의 각 점수에 대해 몇 개 이기는지 계산
        B_scores.sort()
        win_count = 0
        for score in A_scores:
            # A가 이기는 B의 점수 개수 = bisect_left 위치
            win_count += bisect.bisect_left(B_scores, score)

        total_cases = len(A_scores) * len(B_scores)
        win_rate = win_count / total_cases

        if win_rate > max_win_rate:
            max_win_rate = win_rate
            answer = list(A_indices)

    return [i + 1 for i in answer]  # 1-indexed로 변환
