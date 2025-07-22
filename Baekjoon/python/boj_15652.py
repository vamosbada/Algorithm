from sys import stdin
n, m = map(int, stdin.readline().split())

# 결과를 담을 result 리스트 
result = [] 

def backtrack(lst, start):
    # 길이가 m이 되면 백트래킹
    if len(lst) == m:
        # lst값을 계속 써야되므로 복사본을 넣어줌. lst.copy()도 가능함
        result.append(lst[:])
        return
    
    # 시작은 start부터
    for i in range(start, n+1):
        # 리스트에 넣고 재귀 호출하고 없었던 일처럼 요소 제거
        lst.append(i)
        backtrack(lst, i)
        lst.pop()


backtrack([], 1)

# print(len(result))

for val in result:
    print(*val)