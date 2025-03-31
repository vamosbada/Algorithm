#12:30
#boj_14002
from sys import stdin

N = int(stdin.readline())
A = list(map(int, stdin.readline().split()))

dp = [1] * (N+1)
for i in range(1,len(A)):
    for j in range(i):
        if A[i] > A[j]:
            dp[i] = max(dp[i],dp[j]+1)

print(max(dp))
order = max(dp)
result =[]

for i in range(N-1,-1,-1):
    if order == dp[i]:
        result.append(A[i])
        order-=1

print(*sorted(result))
        


    
