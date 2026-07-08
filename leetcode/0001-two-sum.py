# 접근: 원패스 해시맵 — 순회하며 target-num이 이미 dict에 있는지 확인, 없으면 자신을 등록
# 시간 O(n) / 공간 O(n)
# ※ 힌트로 배운 풀이 (1회독 ❌)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement], i]
            seen[num] = i
