from sys import stdin
from collections import deque # 큐를 덱으로 구현
n, m = map(int, stdin.readline().split())
graph = [[] for _ in range(n+1)] # 1-base
result = [float('inf') for _ in range(n+1)]  # 1-base

for _ in range(m):
    a, b = map(int, stdin.readline().split())
    if b not in graph[a]: # 관계가 중복으로 등장하는 것을 막음
        graph[a].append(b)
        graph[b].append(a)

def bfs(start):
    dist = [-1 for _ in range(n+1)]
    q = deque()
    dist[start] = 0
    q.append(start)

    while q:
        cur = q.popleft()
        for next_node in graph[cur]:
            if dist[next_node] == -1: # 방문하지 않았으면(= 거리가 -1이면) 다음 노드 방문
                dist[next_node] = dist[cur] + 1 # 현재 거리에서 +1
                q.append(next_node)
    return dist

for i in range(1, n+1):
    result[i] = sum(bfs(i)[1:])

# print(result)

print(result.index(min(result)))


