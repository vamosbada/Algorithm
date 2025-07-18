def solution(n, wires):
    # 1-base이므로 n+1
    graph = [ [] for i in range(n+1)]
    # graph에는 해당 노드가 다른 어떤 노드들과 연결되어있는지 정리
    for a,b in wires:
        graph[a].append(b)
        graph[b].append(a)

    # solution함수 안에 넣음으로써 solution의 변수들을 매개변수 없이 사용하도록 함
    def dfs(current, parent):
        cnt = 1
        for child in graph[current]:
            # set으로 처리해도 됨. 이 문제에서는 base condition을 부모가 아닌 경우로 설정.
            if child != parent:
                cnt += dfs(child, current)
        return cnt
        

    # 답은 무한대로 설정하고 모든 간선을 끊어가면서 최솟값을 탐색
    answer = float("inf")

    for a,b in wires:
        graph[a].remove(b)
        graph[b].remove(a)
        cnt_a = dfs(a, -1)
        # 하나의 트리이므로 여사건 느낌으로 접금
        cnt_b = n - cnt_a
        answer = min(answer, abs(cnt_a - cnt_b))
        graph[a].append(b)
        graph[b].append(a)
    return answer

print(solution(9, [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]))
print(solution(4, [[1,2],[2,3],[3,4]]))
print(solution(7, [[1,2],[2,7],[3,7],[3,4],[4,5],[6,7]]))