from sys import stdin

n = int(stdin.readline().rstrip())
nums = list(map(int, stdin.readline().split()))

# 배운 것 1: 시간 복잡도 최적화를 위한 '전처리' 과정
# 이 문제를 해결하는 핵심은 O(N^2)의 비효율적인 반복을 피하는 것!
# 이를 위해 for문이 시작되기 전에 시간이 오래 걸리는 작업을 미리 끝낸다.

# ---
# 배운 것 2: '좌표 압축(Coordinate Compression)'이라는 알고리즘 기법
# 값의 크기(ex: 10억)보다 값들의 '상대적인 순서(ex: 0, 1, 2)'가 중요할 때
# 큰 값들을 작은 인덱스로 치환하는 기법을 사용한다.

# 1. 중복을 제거하고(set), 정렬(sorted)해서 순서를 만든다.
new_nums = sorted(set(nums))

# ---
# 배운 것 3: '딕셔너리'를 활용한 O(1) 탐색
# 리스트의 index() 함수는 O(N)이라 느리다.
# 딕셔너리는 해시 기반이라 평균 O(1)으로 빠르게 값을 찾을 수 있다.
# new_nums의 값(val)을 키로, 순서(i)를 값으로 하는 딕셔너리를 만든다.
coord_dict = {val: i for i, val in enumerate(new_nums)}  # O(K log K) or O(K)

# ---
# 배운 것 4: O(N)으로 결과 도출하기
# 이제 원본 리스트(nums)를 한 번만 순회하면서
# 딕셔너리(coord_dict)를 이용해 O(1)로 순서(좌표)를 찾아 결과 리스트를 만든다.
# 이로써 전체 시간 복잡도를 O(N^2)에서 O(N log N)으로 개선한다.
result = [coord_dict[num] for num in nums]

print(*result)