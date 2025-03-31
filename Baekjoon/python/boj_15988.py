#boj_15988
#start:19:57
#finish:20:09

from sys import stdin
N = int(stdin.readline().rstrip())

dp = [0] * 1000003
dp[1] = 1
dp[2] = 2
dp[3] = 4
for i in range(4,1000001):
    dp[i] = (dp[i-3] + dp[i-2] + dp[i-1]) % 1000000009

for _ in range(N):
    val = int(stdin.readline().rstrip())
    print(dp[val])

