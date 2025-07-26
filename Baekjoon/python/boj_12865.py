from sys import stdin
n, k = map(int, stdin.readline().split()) # n개의 배낭과 최대 무게 K
items = [] # 무게와 가치를 저장할 리스트
# 1-base
# dp[i][w] = i번째 물품에서 무게가 w까지 버틸 수 있을 때 최대 가치
dp = [[0 for _ in range(k+1)] for _ in range(n+1)] 

# 무게와 가치를 튜플형태로 저장
for _ in range(n):
    w, v = map(int, stdin.readline().split())
    items.append((w, v))

# 물품을 하나씩 빼냄
for i in range(1, n+1):
    weight, value = items[i-1]

    # 모든 무게를 파악
    for w in range(k+1):
        # 만약에 물품 무게가 저장무게보다 작으면 넣지않거나 넣거나 중에서 비교
        if w >= weight:
            dp[i][w] = max(dp[i-1][w], value + dp[i-1][w-weight])
        # 만약에 물품 무게가 저장무게보다 크면 넣지 않음
        else:
            dp[i][w] = dp[i-1][w]

print(dp[n][k])
