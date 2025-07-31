from sys import stdin

def can_make(length, nums, n):
   """결정함수: length 길이로 n개의 랜선을 만들 수 있는가?
   파라매트릭 서치의 핵심 - 가능/불가능 판단"""
   count = sum(num // length for num in nums)
   return count >= n

k, n = map(int, stdin.readline().split())  # k개의 랜선, n개 필요
nums = []

for _ in range(k):
    num = int(stdin.readline().rstrip())
    nums.append(num)

# 파라매트릭 서치 범위 설정
left, right = 1, max(nums)  # 최소 1cm, 최대 가장 긴 랜선
answer = 0

# 이분탐색으로 최적값(최댓값) 찾기
while left <= right:
    mid = (left+right)//2  # 중간값 시도
    
    if can_make(mid, nums, n):
        answer = mid      # 가능하면 답 갱신
        left = mid + 1    # 더 긴 길이 시도 (최댓값 찾기)
    else:
        right = mid - 1   # 불가능하면 더 짧은 길이 시도

print(answer)  # 만들 수 있는 랜선의 최대 길이 출력

# 시간복잡도: O(k × log(max(nums)))
# 핵심: 단조성(길이↓ → 개수↑), 파라매트릭 서치(최적화→결정문제)