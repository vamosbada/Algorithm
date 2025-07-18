def solution(n, wires):
    graph = [ [] for i in range(n+1)]
    for a,b in wires:
        graph[a].append(b)
        graph[b].append(a)

    def dfs(x):
        cnt = 1
        for child in graph[x]:
            if child != x:
                cnt += dfs(child)
        return cnt
        

    answer = float("inf")

    for a,b in wires:
        graph[a].remove(b)
        graph[a].remove(b)
        cnt_a = dfs(a)
        cnt_b = n - cnt_a
        min_diff = min(min_diff, abs(cnt_a - cnt_b))
        graph[a].append(b)
        graph[b].append(a)
    return answer

print(solution(9, [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]))
print(solution(4, [[1,2],[2,3],[3,4]]))
print(solution(7, [[1,2],[2,7],[3,7],[3,4],[4,5],[6,7]]))