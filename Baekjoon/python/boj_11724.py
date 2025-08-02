# 연결 요소(Connected Component)는 그래프에서 간선으로 연결되어 있는 노드들의 부분 집합
# 이 문제에서는 연결 요소의 개수를 물어봤으므로 그래프가 몇 부분으로 나뉘었는지 구하면 됨
from sys import stdin, setrecursionlimit
setrecursionlimit(10**9) # 파이썬 기본 재귀 깊이인 1000보다 재귀호출 많으므로 제한 풂
n, m = map(int, stdin.readline().split())
graph = [[] for _ in range(n+1)] # 1-based

for _ in range(m):
    u, v = map(int, stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

# print(graph)

vis = set()
cnt = 0

def dfs(node):
    if node in vis:
        return
    vis.add(node)
    for next_node in graph[node]:
        dfs(next_node)

for node in range(1, n+1):
    if node not in vis:
        # print(node)
        cnt += 1
        dfs(node)

print(cnt)