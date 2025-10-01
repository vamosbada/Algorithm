from sys import stdin
import heapq
# 정점, 간선의 개수 입력받음
n, e = map(int, stdin.readline().split())

# 양방향 그래프 설정
graph = [[] for _ in range(n+1)]
for _ in range(e):
    start, end, cost = map(int, stdin.readline().split())
    graph[start].append((cost, end))
    graph[end].append((cost, start))

# 필수로 지나가야 되는 점 입력받음
v1, v2 = map(int, stdin.readline().split())

# 다익스트라 함수
def dijkstr(start, graph):
    dist = [float("INF")] * len(graph)
    queue = [(0,start)]
    dist[start] = 0 # 시작점이 자기 자신이 될 수도 있으므로 0으로 설정
    vis = set()

    while queue:
        curr_dist, curr_node = heapq.heappop(queue)
        if curr_node in vis:
            continue
        vis.add(curr_node)
        
        for next_dist, next_node in graph[curr_node]:
            cost = next_dist + curr_dist
            if cost < dist[next_node]:
                dist[next_node] = cost
                heapq.heappush(queue, (cost, next_node))

    return dist

# 다익스트라를 여러번 돌려서 1->v1->v2->n or n->v2->v1->1 중에서 dist가 짧은걸로 출력
dist_from_1 = dijkstr(1, graph)
dist_from_v1 = dijkstr(v1, graph)
dist_from_v2 = dijkstr(v2, graph)

one_v1_v2_n = dist_from_1[v1] + dist_from_v1[v2] + dist_from_v2[n]
one_v2_v1_n = dist_from_1[v2] + dist_from_v2[v1] + dist_from_v1[n]

dist = min(one_v1_v2_n, one_v2_v1_n)

print(dist) if dist != float("INF") else print(-1)










    
    

