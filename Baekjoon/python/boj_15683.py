from sys import stdin
import copy

# 보드 사이즈 입력받음
n, m = map(int, stdin.readline().split())
board = []
# cctv의 위치를 저장할 리스트, idx가 cctv종류이고 값이 좌표
cctv = []

# 기본 움직임 설정
dr = [1, 0, -1, 0]
dc = [0, 1, 0, -1]

# cctv들의 움직임을 설정
cctv_direction = {1 : [[0], [1], [2], [3]], 2 : [[0, 2], [1, 3]], 
                  3 : [[0, 1], [1, 2], [2, 3], [3, 0]], 4 : [[3, 0, 1], [1, 2, 3], [0, 1, 2], [2, 3, 0]],
                  5 : [[0, 1, 2, 3]]}

# 보드에 표시하는 함수
def mark_direction(board, r, c, direction):
    nr, nc = r + dr[direction], c + dc[direction]

    # 끝까지 한 방향으로 직진함
    while 0 <= nr < n and 0 <= nc < m:
        if board[nr][nc]  == 6:
            break
        if board[nr][nc] == 0:
            board[nr][nc] = -1
        nr += dr[direction]
        nc += dc[direction]

# 사각지대를 찾는 함수, 0인 부분이 사각지대임
def count_blind_spots(board):
    cnt = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] == 0:
                cnt += 1
    return cnt

# 재귀 호출함수
def dfs(idx, board):
    global min_blind_spots
    # 끝까지 다다르면 기존 최솟값과 새로 구한 blind_spot중에 최솟값을 구함
    if idx == len(cctv):
        blind_spots = count_blind_spots(board)
        min_blind_spots = min(blind_spots, min_blind_spots)
        return

    # cctv 좌표와 타입을 꺼냄
    r, c, cctv_type = cctv[idx]
    # 방향에 따라 새로운 보드에 계산
    for directions in cctv_direction[cctv_type]:
        new_board  = copy.deepcopy(board)
        # 모든 방향을 마킹 한 후에 다시 재귀 호출
        for direction in directions:
            mark_direction(new_board, r, c, direction)
        dfs(idx + 1, new_board)
    return
    

for row_idx in range(n):
    row = list(map(int, stdin.readline().split()))
    board.append(row)
    # 0빼고는 다 넣음
    for col_idx, value in enumerate(row):
        # 값이 0이나 6이 아니면 cctv임
        if value not in [0, 6]:
           cctv.append((row_idx, col_idx, value))

min_blind_spots = count_blind_spots(board)

dfs(0, board)

print(min_blind_spots)

        
    



    
