import heapq
from sys import stdin
# input()함수보다 시스템으로 입력받는게 더 빠름 + 대규모 입력 아닌 이상 필요할 때마다 입력 받기
n = int(stdin.readline().rstrip())
m = int(stdin.readline().rstrip())
# 1-base
graph = [[] for _ in range(n+1)]
dist = [float("inf") for _ in range(n+1)]

for _ in range(m):
    # map(a,b) = a라는 함수로 b라는 iterable객체 처리
    # split()에는 자동으로 개행문자 제거 있으니까 rstrip() 안써도됨
    a, b, cost = map(int, stdin.readline().split())
    graph[a].append((b, cost))

start, end = map(int, stdin.readline().split())
dist[start] = 0
queue = []
# 시작노드는 거리(비용)를 0으로 힙에 넣음
heapq.heappush(queue, (0, start))

# 어느 노드를 탐색했나 중복 방지용으로 제작
vis = set()

while queue:
    current_dist, current = heapq.heappop(queue)
    # 방문한 적이 있다면 패스(=최단거리에 포함된다면)
    if current in vis:
        continue
    vis.add(current)

    for next, next_dist in graph[current]:
        cost = next_dist + dist[current]
        if cost < dist[next]:
            dist[next] = cost
            heapq.heappush(queue, (cost, next))

print(dist[end])
        