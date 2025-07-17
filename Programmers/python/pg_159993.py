# 11:00
# 맵 만든다,(시작점 끝점 레버)위치 기억 -> bfs를 돌린뒤 if exit or 레버가 미방문이면 -1 출력 아니면 시간 출력
from collections import deque
def solution(maps):
    # 행과 열을 정한다.
    rows = len(maps)
    cols = len(maps[0])

    # 시작점, 끝점, 레버 좌표 정함. # 파이썬은 함수 단위로 변수 스코프 할당됨
    for r in range(rows):
        for c in range(cols):
            if maps[r][c] == 'S': start = (r, c)
            elif maps[r][c] == 'E': end = (r, c)
            elif maps[r][c] == 'L': lever = (r, c)
    
    # BFS 로직을 수행하는 함수
    def BFS(start_pos, end_pos):
        queue = deque([(*start_pos,0)]) # []으로 가두지 않으면 튜플이 요소가 각각 할당되므로 초기 덱의 요소가 3개인 상태로 시작함
        # 방문 배열은 매번 초기화
        visited = [[False for _ in range(cols)] for _ in range(rows)]
        visited[start_pos[0]][start_pos[1]] = True

        # 이동을 하는 배열을 만들어줌 : dr은 행이동, dc는 열이동 # 앞으로 문제 풀 때 행관련은 x대신 r, 열관련은 y대신 c 쓰기
        dr = [0, 1, 0, -1]
        dc = [1, 0, -1, 0]

        # 큐가 빌 때까지 반복
        while queue:
            cur_r, cur_c, dist = queue.popleft()

            if (cur_r, cur_c) == end_pos: return dist

            for i in range(4):
                nr, nc = cur_r + dr[i], cur_c + dc[i]

                # 범위나 조건에 어긋나서 안한다 보다는 이 범위나 조건에 해당되므로 실행된다가 코드길이가 짧고 좋음
                if 0 <= nr < rows and 0 <= nc < cols and not visited[nr][nc] and maps[nr][nc] != 'X':
                    visited[nr][nc] = True
                    queue.append((nr, nc, dist+1))
    
        return -1

    # S -> L 가는데 못찾을경우(=-1) -1 반환
    time_to_lever = BFS(start, lever)

    if time_to_lever == -1:
        return -1
    
    # L -> E 가는데 못찾을경우(=-1) -1 반환
    time_to_exit = BFS(lever, end)

    if time_to_exit == -1:
        return -1
    
    return time_to_lever + time_to_exit
    
maps = ["SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"]
print(solution(maps))

maps =["LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"]
print(solution(maps))