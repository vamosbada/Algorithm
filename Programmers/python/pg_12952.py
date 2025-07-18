def solution(n):
    # 열을 체크할 배열
    col = [False for _ in range(n)]
    # 우대각선을 체크할 배열(넉넉히 제곱으로 잡음) + 왼쪽 위부터 0
    diag1 = [False for _ in range(n**2)]
    # 좌대각선을 체크할 배열(넉넉히 제곱으로 잡음) + 왼쪽 아래부터 0
    diag2 = [False for _ in range(n**2)]

    def backtrack(row):
        # 맨 끝으로 가면 + 1 = 개별 가지에 대해 처리하는 코드
        if row == n:
            return 1
        
        # 개별 가지들을 모아서 분기를 합칠 변수
        count = 0
        # 모든 열들을 탐색
        for c in range(n):
            d1 = c + row
            # 통일성 있게 0-base로 맞춰줬음
            d2 = c - row + n - 1
            # 열,우대각,좌대각 중에 하나라도 참이 있으면 백트래킹
            if not(col[c] or diag1[d1] or diag2[d2]):
                # True -> 재귀 -> False로 재귀가 끝나고 돌아온 뒤에는 없었던 것처럼 처리
                col[c] = diag1[d1] = diag2[d2] = True
                count += backtrack(row + 1)    
                col[c] = diag1[d1] = diag2[d2] = False
    
        return count
    
    return backtrack(0)

print(solution(4))