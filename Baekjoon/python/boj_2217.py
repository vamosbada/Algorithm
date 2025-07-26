# 매 순간 최적의 선택이 전체적으로도 최적의 결과를 낳음
from sys import stdin
n = int(stdin.readline().rstrip())
ropes = []

for _ in range(n):
    rope = int(stdin.readline().rstrip())
    ropes.append(rope)

ropes.sort()
ans = 0
for i in range(1, n+1):
    ans = max(ans, ropes[n-i] * i)

print(ans)