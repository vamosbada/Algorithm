def solution(n, computers):
    parents = list(range(n)) # [range(n)]이면 range 객체 1개가 들어가있다는 뜻임, list(range(n))으로 써야됨

    def find(x): # find의 인자로 parent를 줄 필요가 없음
        if parents[x] != x:
            parents[x] = find(parents[x])
        return parents[x]
    
    def union(x, y):
        root1 = find(x)
        root2 = find(y)
        if root1 != root2:
            parents[root1] = root2
        return None

    for i in range(n):
        for j in range(n):
            if i != j and computers[i][j] == 1: 
                union(i,j)

    return len(set(find(i) for i in range(n)))

print(solution(3,[[1, 1, 0], [1, 1, 0], [0, 0, 1]]))

