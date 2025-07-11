def solution(n, costs):
    costs.sort(key=lambda x:x[2]) # sort가 cost[i]를 x에 주고 x의 2번째 인덱스로 정렬한다.
    # who = {} 빈 딕셔너리를 의미함
    who = set()
    total = []
    parents = list(range(n))
    def find(parents, x):
        if parents[x] == x:
            return x
        parents[x] = find(parents, parents[x])
        return parents[x]
    
    def union(parents, x, y):
        # x와 y의 루트 노드를 각각 찾는다
        root1 = find(parents, x)
        root2 = find(parents, y)

        # 두 루트 노드가 다르다면, 아직 다른 집합이라는 의미
        if root1 != root2:
            # 두 집합을 합치고 True를 반환 (간선 추가 성공)
            parents[root1] = root2
            return True
    
    # 두 루트 노드가 같다면, 이미 같은 집합이므로 False를 반환 (간선 추가 실패)
        return False

    total_cost = 0
    edge_count = 0

    # 정렬된 간선을 하나씩 순회
    for x, y, cost in costs:
        # union 함수를 호출해서 두 노드를 합치는 데 성공했다면 (True 라면)
        if union(parents, x, y):
            # 비용을 더하고, 선택된 간선 개수를 1 증가시킨다
            total_cost += cost
            edge_count += 1
            
            # 선택된 간선의 개수가 n-1개가 되면 MST가 완성된 것이므로
            if edge_count == n - 1:
                # 더 이상 볼 필요 없이 즉시 반복문을 탈출한다
                break
    
    # 반복이 끝난 뒤, 계산된 최종 비용을 반환한다
    return total_cost

# print(solution(4,[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]))
print(solution(6, [[0,1,3],[1,2,4],[2,3,2],[3,4,1],[4,0,5],[4,5,3],[2,5,4],[1,5,2]]))
