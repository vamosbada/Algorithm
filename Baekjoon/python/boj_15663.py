from sys import stdin
from collections import Counter 
n, m = map(int, stdin.readline().split())
nums = sorted(list(map(int, stdin.readline().split())))
unique_num = sorted(list(set(nums))) # set으로 중복 처리
cnt = Counter(nums) # 리스트에 있는 요소들의 개수를 세어 딕셔너리 형태로 반환
result = []


def backtrack(seq):
    if len(seq) == m: # 길이가 m이면 복사본 반환
        result.append(seq[:])
        return
    
    for idx in range(len(unique_num)): # 매번 모든 숫자를 세어야되므로 0부터 시작 + 중복 횟수반영은 밑에서 처리
        num = unique_num[idx] 
        if cnt[num] > 0: # 이 숫자가 사용가능한지(=횟수가 남았는지 체크)
            seq.append(num) # 가능하다면 넣고 횟수 차감하고 재귀 호출한 뒤에 다시 횟수 복구
            cnt[num] -= 1
            backtrack(seq)
            cnt[num] += 1
            seq.pop()

backtrack([])

for val in result:
    print(*val)