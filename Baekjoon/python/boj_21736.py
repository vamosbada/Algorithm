from sys import stdin
from collections import deque
n, m = map(int, stdin.readline().split())
vis = [[False for _ in range(m)] for _ in range(n)]
board = []
dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]
start = (0, 0)

for i in range(n):
    row = list(stdin.readline().rstrip())
    if 'I' in row:
        start = (i, row.index('I'))
    board.append(row)

q = deque([start])
vis[start[0]][start[1]] = True
cnt = 0

while q:
    cur = q.popleft()
    if board[cur[0]][cur[1]] == 'P':
        cnt += 1

    for i in range(4):
        nr = cur[0] + dr[i]
        nc = cur[1] + dc[i]
        if 0 <= nr < n and 0 <= nc < m and board[nr][nc] != 'X' and vis[nr][nc] == False:
            q.append((nr, nc))
            vis[nr][nc] = True

if cnt == 0:
    print('TT')
else:
    print(cnt)

