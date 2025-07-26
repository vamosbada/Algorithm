from sys import stdin
n, m = map(int, stdin.readline().split()) 
nums = list(map(int, stdin.readline().split()))
nums.sort() # 비내림차순이므로 정렬함
result = [] # 결과를 저장할 리스트 설정

def backtrack(seq, start):
    # 길이가 m이면 복사본을 결과에 저장
    if len(seq) == m: 
        result.append(seq[:])
        return
    
    # 기준점부터 끝까지 돌아가면서 넣고 재귀호출하고 없었던 일처럼 pop
    for i in range(start, len(nums)):
        seq.append(nums[i])
        backtrack(seq, i)
        seq.pop()

backtrack([], 0)

# 일단 중복을 없애야되므로 set, dict.fromkeys(=iterable한 존재를 키로 삼아 딕셔너리 만듦)
# set은 순서보장 안하고 dict.fromkeys는 순서 보장함
# key는 바꿀 수 없어야 되는 값이므로 리스트형태인 result를 바로 넣으면 망가짐
# 따라서 튜플로 바꾼 뒤에 넣어줌
tuple_results = [tuple(item) for item in result]
for tuple in list(dict.fromkeys(tuple_results)):
    print(*tuple)