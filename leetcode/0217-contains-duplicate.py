# defaultdict로 등장 횟수 카운트, 값이 2가 되는 순간 중복 존재로 판정
# Time: O(n) / Space: O(n)
from collections import defaultdict

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums_dict = defaultdict(int)
        for num in nums:
            nums_dict[num] += 1
            if nums_dict[num] == 2: return True

        return False
