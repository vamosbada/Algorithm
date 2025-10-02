# boj_1238
from sys import stdin
import heapq
# 정점의 수, 간선의 수, 파티장 위치를 입력받음
n, m, party = map(int, stdin.readline().split())

# 그래프 입력받음
graph = [[] for _ in range(n+1)]
for _ in range(m):
    start, end, dist = map(int, stdin.readline().split())
    graph[start].append((dist, end))


# 다익스트라 함수
def dijkstra(start):
    dist = [float("inf")] * len(graph)
    vis = set()
    queue = []
    dist[start] = 0
    heapq.heappush(queue, (0, start))

    while queue:
        curr_dist, curr_node = heapq.heappop(queue)

        if curr_node in vis:
            continue
        vis.add(curr_node)

        for next_dist, next_node in graph[curr_node]:
            cost = curr_dist + next_dist 
            if cost < dist[next_node]:
                dist[next_node] = cost
                heapq.heappush(queue, (cost, next_node))
    return dist

# 각 정점들의 왕복값을 비교하며 최댓값을 찾음
res = 0
for i in range(1, n+1):
    if i == party:
        continue
    res = max(dijkstra(i)[party] + dijkstra(party)[i], res)
print(res)




