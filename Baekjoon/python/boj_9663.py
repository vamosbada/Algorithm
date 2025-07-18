from sys import stdin
n = int(stdin.readline().rstrip())
# 퀸의 움직임을 체크하는 순서대로 열,우대각((0,0)이 index 0),좌대각((n-1,0)이 index 0)
col = [False for _ in range(n)]
diag1 = [False for _ in range(n**2)]
diag2 = [False for _ in range(n**2)]

def backtrack(row):
    # 끝까지 도달하면 +1 = 개별 가지
    if row == n:
        return 1
    #

    count = 0
    for c in range(n):
        d1 = row + c
        d2 = row - c + n - 1
        # 열,우대각,좌대각 모두 안걸리면 count에 더함. 여러 분기를 더해주는 느낌이고 재귀함수는 각각의 count변수를 가진다.
        if not(col[c] or diag1[d1] or diag2[d2]):
            col[c] = diag1[d1] = diag2[d2] = True
            count += backtrack(row + 1)
            col[c] = diag1[d1] = diag2[d2] = False
    return count

print(backtrack(0))