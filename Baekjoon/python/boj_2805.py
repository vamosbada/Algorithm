from sys import stdin
n, m = map(int, stdin.readline().split())
trees = list(map(int, stdin.readline().split()))

# parametrice search의 결정함수
# 단조함수여야되고 어느 일정 값을 기준으로 나뉘는 느낌이면 사용함
def can_make(length):
    return sum([val-length if val >= length else 0 for val in trees]) >= m

left, right = 1, max(trees)
answer = 0

while left <= right:
    mid = (left+right)//2

    if can_make(mid):
        answer = mid
        left = mid + 1
    else:
        right = mid - 1

print(answer)