from sys import stdin
n = int(stdin.readline().rstrip())
adjacent_matrix = [[] for _ in range(n+1)] # 1-base
result = [[0 for _ in range(n)] for _ in range(n)] # 0-base

for r in range(1, n+1):
    row = list(map(int, stdin.readline().split()))
    for i in range(len(row)):
        if row[i] == 1:
            adjacent_matrix[r].append(i+1)

# print(adjacent_matrix)

# bfs의 경우에는 vis를 만들어서 한 번 갔으면 방문처리 하면 안되지만 모든 경로 탐색에서는 방문처리 하면 안됨
def dfs(start, current):  # vis 없이!
    for next_node in adjacent_matrix[current]:
        if result[start-1][next_node-1] == 0:  # 아직 미발견 경로
            result[start-1][next_node-1] = 1   # 경로 기록
            dfs(start, next_node)              # 계속 탐색
    

for i in range(1, n+1):
    dfs(i, i)

for row in result:
    print(*row)
