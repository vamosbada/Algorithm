from sys import stdin

# 입력: N(표 크기), M(쿼리 개수)
n, m = map(int, stdin.readline().split())  

# N×N 표 입력받기 (0-based 인덱싱)
board = []
for _ in range(n):
   row = list(map(int, stdin.readline().split()))
   board.append(row)

# 2차원 누적합 배열 생성 (1-based 인덱싱으로 경계 처리 간단화)
# prefix[i][j] = (1,1)부터 (i,j)까지의 직사각형 합
prefix = [[0] * (n+1) for _ in range(n+1)]

# 누적합 계산
for i in range(1, n+1):
   for j in range(1, n+1):
       # 현재 위치 = 위쪽 누적합 + 왼쪽 누적합 - 중복된 대각선 + 현재 값
       prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + board[i-1][j-1]

# M개의 쿼리 처리
for _ in range(m):
   # (x1,y1)부터 (x2,y2)까지의 직사각형 합 구하기
   x1, y1, x2, y2 = map(int, stdin.readline().split())
   
   # 구간합 공식: 전체 - 위쪽 제외 - 왼쪽 제외 + 중복 제외된 부분 복구
   ans = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1]
   print(ans)