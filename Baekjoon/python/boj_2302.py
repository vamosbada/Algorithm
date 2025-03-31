#boj_2303 #20:29 #21:51
from sys import stdin
N = int(stdin.readline().rstrip())
M = int(stdin.readline().rstrip())
start = 0
dist = []
#거리를 저장하는 배열 생성
for i in range(M):
    cur = int(stdin.readline().rstrip())
    dist.append(cur-start-1)
    start = cur
dist.append(N-start)
# print(dist)
save = [[1]]
dp = [1,1]
#n만큼의 길이 = 피보나치 n번째 항
for i in range(2,max(dist)+1):
    dp.append(dp[i-1] + dp[i-2])

#동시에 일어나는 경우이므로 곱해서 구한다.
result = 1
for i in dist:
    result *= dp[i]

print(result)
