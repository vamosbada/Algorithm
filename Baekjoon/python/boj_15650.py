# boj_15650
from sys import stdin
n, m = map(int, stdin.readline().split())

result = [] # 최종 값을 반환하는 리스트

def backtrack(lst, start):

    # 길이가 m이면 반환, 하지만 누적되는 값을 계속 사용해야되므로 복사본인 lst.copy나 lst.[:]를 전달
    if len(lst) == m:
        result.append(lst.copy())
        return
    
    # "현재 숫자 i를 리스트에 추가 → 재귀 호출 → 다음 경우를 위해 제거"
    for i in range(start, n+1):
        lst.append(i)
        # print(lst)
        backtrack(lst, i+1)
        lst.pop()

# 빈 리스트에 1부터 넣으면 알아서 오름차순 정렬 및 모든 케이스 탐색 가능
backtrack([], 1)

# print(result)

# 언패킹으로 값 출력
for val in result:
    print(*val)