from sys import stdin
n, m, k = map(int, stdin.readline().split())
board = [[0 for _ in range(m)] for _ in range(n)]

# 90도 회전하는 함수
def rotate(sticker):
    r, c = len(sticker), len(sticker[0])
    new_sticker = [[0] * r for _ in range(c)] # 회전을 하면 행과 열의 크기가 바뀜
    
    # 좌표평면과 행렬에서의 90도 회전은 서로 다름
    for i in range(r):
        for j in range(c):
            new_sticker[j][r-1-i] = sticker[i][j]
    return new_sticker

# 스티커를 붙일 수 있는지 확인
def can_place_sticker(board, sticker, start_r, start_c):
    """스티커를 (start_r, start_c)에 붙일 수 있는지 확인"""
    r, c = len(sticker), len(sticker[0])
    
    # 범위 체크
    if start_r + r > n or start_c + c > m:
        return False
    
    # 겹치는지 체크
    for i in range(r):
        for j in range(c):
            if sticker[i][j] == 1 and board[start_r + i][start_c + j] == 1:
                return False
    return True

def place_sticker(board, sticker, start_r, start_c):
    """실제로 스티커를 보드에 붙이기"""
    r, c = len(sticker), len(sticker[0])
    for i in range(r):
        for j in range(c):
            if sticker[i][j] == 1:
                board[start_r + i][start_c + j] = 1

def try_place_sticker(board, sticker):
    """스티커를 붙이려고 시도, 성공하면 True 리턴"""
    for i in range(n):
        for j in range(m):
            if can_place_sticker(board, sticker, i, j):
                place_sticker(board, sticker, i, j)
                return True
    return False


for _ in range(k):  # k개의 스티커
    r, c = map(int, stdin.readline().split())
    sticker = []
    for _ in range(r):
        row = list(map(int, stdin.readline().split()))
        sticker.append(row)

    # 메인 로직
    for rotation in range(4):
        if try_place_sticker(board, sticker):
            break  # 붙였으면 끝
        sticker = rotate(sticker)# 다음 회전


print(sum(1 for row in board for val in row if val))
        