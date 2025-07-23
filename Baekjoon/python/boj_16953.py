from sys import stdin
from collections import defaultdict
a, b = map(int, stdin.readline().split())
count = defaultdict(int) # 기본값이 0이고 키가 기존에 존재하지 않아도 키-값 넣으면 에러없이 할당해줌

def backtrack(num, cnt):
    next_num1 = num * 2 # 곱하기 2
    next_num2 = int(str(num) + "1") # 뒤에 1붙이기
    # 곱하기 2 했는데 범위 넘어가면 반환하고 아님 백트래킹
    if next_num1 > b: 
        count[num] = cnt
        return
    else:
        backtrack(next_num1, cnt+1)
    # 뒤에 1 붙이기 했는데 범위 넘어가면 반환하고 아님 백트래킹
    if next_num2 > b:
        count[num] = cnt
        return
    else:
        backtrack(next_num2, cnt+1)

backtrack(a, 1)

result = count[b] if count[b] else -1 # 참일 때 실행될 값 if 조건식 else 부정일 때 실행될 값
print(result)