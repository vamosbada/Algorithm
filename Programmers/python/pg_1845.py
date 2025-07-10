# 10:48 ~ 11:01

def solution(nums):
    return len(nums)//2 if len(set(nums)) >= len(nums)//2 else len(set(nums))
    # return min(len(nums)//2, len(set(nums))) 도 가능함

print(solution([3,1,2,3]))