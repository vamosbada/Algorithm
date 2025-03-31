#boj_11052 #11:53~12:29, 13:22~
from sys import stdin
N = int(stdin.readline().rstrip())
price = [0]
price += list(map(int,stdin.readline().rstrip().split()))

dp = [0] * (N+1)
for i in range(1,N+1):
    if i == 1:
        dp[1] = price[1]
        continue
    
    for j in range(1,i+1):
        dp[i] = max(price[j] + dp[i-j],dp[i])

print(dp[N]) 
    
    

        
