from sys import stdin
import heapq

# 마을과 버스의 숫자를 입력받음
n = int(stdin.readline().rstrip())
m = int(stdin.readline().rstrip())

# 그래프를 설정, 거리 배열 설정, 역추적 배열 설정
graph = [[] for _ in range(n+1)]
dist = [float("inf")] * len(graph)
parent = [-1] * len(graph)

for _ in range(m):
    start, end, cost = map(int, stdin.readline().split())
    graph[start].append((cost, end))

# 시작점과 끝점을 입력받음
a, b = map(int, stdin.readline().split())

dist[a] = 0
queue = []
queue.append((0, a))
vis = set()

while queue:
    curr_dist, curr_node = heapq.heappop(queue)
    
    if curr_node in vis:
        continue
    vis.add(curr_node)

    for next_dist, next_node in graph[curr_node]:
        cost = next_dist + curr_dist
        if cost < dist[next_node]:
            parent[next_node] = curr_node
            dist[next_node] = cost
            heapq.heappush(queue, (cost, next_node))
        
print(dist[b])

# 역추적
path = []
node = b
while node != -1:
    path.append(node)
    node = parent[node]

path.reverse()
print(len(path))
print(*path)
    
    

