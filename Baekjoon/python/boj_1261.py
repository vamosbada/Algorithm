from sys import stdin
import heapq
# 보드 움직임 배열
dr = [1, 0, -1, 0]
dc = [0, 1, 0, -1]

# 보드 제작(0-based)
m, n = map(int, stdin.readline().split())
board = [] 

for row in range(n):
    col = [int(x) for x in stdin.readline().rstrip()]
    board.append(col)

# 거리배열
dist  = [[float("INF")] * (m) for _ in range(n)]

# print(*dist)

# 비용이 최소가 되는 이론인 다익스트라 사용
# 비용, 행, 열 순으로 우선순위 큐에 넣음
queue = [(0, 0, 0)]
dist[0][0] = 0

while queue:
    cost, cur_r,  cur_c = heapq.heappop(queue)
    if cost > dist[cur_r][cur_c]:  # 이미 더 짧은 경로로 방문했으면 continue
        continue

    for i in range(4):
        nr, nc = cur_r + dr[i], cur_c + dc[i]

        # 보드에 벗어나지 않았나 체크
        if 0 <= nr < n and 0 <= nc < m:
            new_cost = cost + board[nr][nc]  # 새로운 비용
            
            if new_cost < dist[nr][nc]:  # 더 싸면
                dist[nr][nc] = new_cost   # 갱신
                heapq.heappush(queue, (new_cost, nr, nc))  # 큐에 추가


print(dist[n-1][m-1])




