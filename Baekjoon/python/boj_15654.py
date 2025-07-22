from sys import stdin
n, m = map(int, stdin.readline().split())

# 문제에서 "정수", "자연수" 같이 명시할 경우에는 직접적으로 int로 바꿔야함
# "1","10", "2"의 정렬과 1,10,2의 정렬은 다름(전자는 1 10 2, 후자는 1 2 10)
lst = list(map(int, stdin.readline().split()))
lst.sort()

result = []

def backtrack(seq):
    # 일정길이가 되면 반환
    if len(seq) == m:
        # seq값을 계속 누적하면서 사용해야되므로 복사본 사용
        result.append(seq[:])
        return
    
    # 수열에 없으면 포함시켜서 재귀 호출하고 다시 없었던 일처럼 요소 제거
    for ele in lst:
        if ele not in seq:
            seq.append(ele)
            backtrack(seq)
            seq.pop()

backtrack([])

# print(len(result))

for val in result:
    print(*val)

