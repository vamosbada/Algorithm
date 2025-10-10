from sys import stdin
import heapq

# 도시, 길, 면접장의 개수를 입력받음
cities, roads, cnt = map(int, stdin.readline().split())

# 그래프 처리
# 모든 도시에서 특정 면접장을 가는 다익스트라 = 특정 면접장에서 모든 도시로 가는 다익스트라
# 역방향 그래프를 이용
reverse_graph = [[] for _ in range(cities+1)]

for _ in range(roads):
    u, v, cost = map(int, stdin.readline().split())
    reverse_graph[v].append((cost, u))

# 면접장 위치 입력받음
interview_places = list(map(int, stdin.readline().split()))

# 먼접장의 위치를 한 번에 큐에 넣고 다익스트라를 한 번 돌림
# 1-base이므로 index 0의 값은 -1로 처리
dist = [float("INF") for _ in range(cities+1)]
dist[0] = -1
queue = []

# 여러 면접장을 하나의 큐에 넣어 단 한 번의 다익스트라를 실행
# 다익스트라의 시간복잡도는 O(n) = elog(v)임(모든 간선을 탐색할 때 log(v)로 노드를 탐색하기 때문)
for town in interview_places:
    heapq.heappush(queue, (0, town))
    dist[town] = 0

vis = set()

while queue:
    cur_cost, cur_node = heapq.heappop(queue)
    if cur_node in vis:
        continue
    vis.add(cur_node)

    for next_cost, next_node in reverse_graph[cur_node]:
        cost = cur_cost + next_cost
        if cost < dist[next_node]:
            dist[next_node] = cost
            heapq.heappush(queue, (cost, next_node))

# 가장 큰 값을 찾고 그에 대한 index를 구함
maxVal = max(dist)
print(dist.index(maxVal))
print(maxVal)




    




