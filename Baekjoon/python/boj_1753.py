from sys import stdin
# 다익스트라는 최소 힙으로 구현
import heapq
v, e = map(int, stdin.readline().split())
# 1-base
graph = [[] for _ in range(v+1)]
# 처음에 모두 무한대로 초기화
dist = [float("inf") for _ in range(v+1)]
start = int(stdin.readline().rstrip())
# 방향그래프는 단방향임
for _ in range(e):
    a, b, cost = map(int, stdin.readline().split())
    graph[a].append((b, cost))

queue = []
dist[start] = 0
# 최소 힙은 인덱스 0 값들 기준으로 정렬됨
heapq.heappush(queue, (0, start))
vis = set()

# 모든 노드를 탐색할 동안 반복
while queue:
    curr_dist, curr_node = heapq.heappop(queue)

    # 방문을 한 적(=이미 최단경로)이 있으면 스킵
    if curr_node in vis:
        continue
    vis.add(curr_node)
    
    # 해당 노드와 연결된 모든 노드 탐색
    for next_node, next_dist in graph[curr_node]:
        cost = curr_dist + next_dist
        if cost < dist[next_node]:
            heapq.heappush(queue, (cost, next_node))
            dist[next_node] = cost
    
for i in range(1, v+1):
    print(dist[i] if dist[i] != float("inf") else "INF")
            
    



