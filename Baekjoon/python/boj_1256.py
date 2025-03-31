#boj_1256
#14:14
from sys import stdin
N = int(stdin.readline())
dp = [[0 for _ in range(3)] for _ in range(N+1)]

for i in range(1,N+1):
    cur = int(stdin.readline())
    if i == 1:
        dp[i][1] = cur
        dp[i][2] = 0
        continue
    M = max(max(row) for row in dp[:i-1])
    dp[i][1] = M + cur
    dp[i][2] = cur + dp[i-1][1]

# print(dp)
print(max(max(row) for row in dp))

