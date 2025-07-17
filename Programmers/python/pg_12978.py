# 다익스트라는 우선순위큐로 구현, heapq = 힙 만들어주는 관리자
import heapq

def solution(N, road, k):
    # 1-base이니까 N+1
    graph = [[] for _ in range(N+1)]
    # float('inf') = 무한대
    distance = [float('inf') for _ in range(N+1)]
    # 첫 노드의 거리는 0
    distance[1] = 0

    # 양방향 처리 및 각 노드에 연결된 간선들을 저장
    for a,b,cost in road:
        graph[a].append((b, cost))
        graph[b].append((a, cost))

    # 우선순위 큐로 사용할 큐 제작
    queue = []
    # heapq로 최소힙처럼 리스트를 다룬다.
    heapq.heappush(queue, (0, 1))
    # 이미 처리된 노드 중복처리 방지용으로 제작
    vis = set()
    
    # 최소 힙 돌아가는 동안 = 각 노드가 탐색될 동안
    while queue:
        dist, node = heapq.heappop(queue)
        # 이미 방문한 적 있으면 패스
        if node in vis:
            continue
        # 방문한 적 없다면 추가
        vis.add(node)

        # 해당 노드와 연결되어있는 모든 노드를 탐색
        for next_node, next_dist in graph[node]:
            cost = dist + next_dist
            # 최단거리라고 판단되면 최소힙에 넣고 최단거리 반영
            if cost < distance[next_node]:
                distance[next_node] = cost
                heapq.heappush(queue, (cost,next_node))
    
    # k보다 작은 친구들의 합
    return sum([1 for val in distance if val <= k])

print(solution(6, [[1,2,1],[1,3,2],[2,3,2],[3,4,3],[3,5,2],[3,5,3],[5,6,1]], 4))