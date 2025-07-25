from sys import stdin
from itertools import combinations # 치킨집 선택하기 위해서 조합 데려옴
n, m = map(int, stdin.readline().split())
chicken = [] # 치킨집 좌표
houses = [] # 집 좌표
dist = float("inf") # 답

# 치킨집과 집 좌표를 구해서 리스트에 튜플로 넣음
for row_idx in range(n):
    row = list(map(int, stdin.readline().split()))
    for col, value in enumerate(row):
        if value == 1: # 값이 1이면 집
            houses.append((row_idx, col))
        elif value == 2: # 값이 2이면 집
            chicken.append((row_idx, col))
# 치킨집중에서 m개만 선택, math의 comb는 값을 구해주고 itertools의 combination은 조합의 결과물들을 얻게 해줌
selected_chicken = list(combinations(chicken, m))


# 기존 bfs 문제와 다르게 벽이 없으므로 맨해튼 거리(가로 + 세로)로 구함
def house_to_chicken(houses, chicken_list):
    distance = 0
    for house in houses:
        how_far = float("inf")
        for dest in chicken_list:
            how_far = min(how_far, abs(house[0]-dest[0]) + abs(house[1]-dest[1]))
        distance += how_far
    return distance

for chicken_list in selected_chicken:
    dist = min(dist, house_to_chicken(houses, chicken_list))

print(dist)

        


