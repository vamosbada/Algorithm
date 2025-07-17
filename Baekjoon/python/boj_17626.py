#boj_17626
from sys import stdin
from math import sqrt
n = int(stdin.readline().rstrip())
dp = [0] * 50001

dp[1] = 1
for i in range(2,n+1):
    if sqrt(i) % 1 == 0:
        dp[i] = 1
        continue
    else:
        min_val = 4
        j = 1
        while j * j <= i:
            min_val = min(min_val, dp[i-j*j])
            j += 1
        dp[i] = min_val + 1

# for i in range(1,10):
#     print(f'dp[{i}] = ',dp[i])

print(dp[n])
        

