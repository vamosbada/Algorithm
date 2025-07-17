from collections import deque
def solution(maps):
    # move라는 하나의 배열보다 dr,dc로 나누는 것이 나음.튜플 생성보다 인덱스 접근이 빠르기 때문
    dr = [1,-1,0,0]
    dc = [0,0,1,-1]
    n = len(maps)
    m = len(maps[0])
    dist = [[-1 for _ in range(m)] for _ in range(n)]
    queue = deque([(0,0)]) # 리스트보다 튜플로 주는 것이 나음(안정성 이슈)
    dist[0][0] = 1
    while queue:
        cur_r, cur_c = queue.popleft()
        print(cur_r, cur_c)
        for i in range(4):
            nr = cur_r + dr[i]
            nc = cur_c + dc[i]
            if 0 <= nr < n and 0 <= nc < m and maps[nr][nc] == 1 and dist[nr][nc] == -1: # 여러 개의 분기보다는 하나의 if로 처리
                queue.append((nr, nc))
                dist[nr][nc] = dist[cur_r][cur_c] + 1
    for row in dist:
        print(row)
        
    return dist[n-1][m-1]


print(solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]))
