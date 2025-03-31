#boj_9465 #이틀걸림
from sys import stdin
T = int(stdin.readline().rstrip())
for _ in range(T):
    N = int(stdin.readline().rstrip())
    dp = [list(map(int,stdin.readline().rstrip().split()))  for _ in range(2)]
    if N == 1:
        print(max(dp[0][0],dp[1][0]))
        continue
    dp[0][1] += dp[1][0]
    dp[1][1] += dp[0][0]

    for i in range(2,N):
        dp[0][i] += max(dp[1][i-1],dp[1][i-2])
        dp[1][i] += max(dp[0][i-1],dp[0][i-2])
    
    print(max(dp[0][N-1],dp[1][N-1]))




