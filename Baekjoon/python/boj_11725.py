from sys import stdin, setrecursionlimit
setrecursionlimit(10 ** 9) # 이 문제에서는 최대 재귀가 10만번까지 호출되므로 최댓값 변경
n = int(stdin.readline().rstrip())
# 트리 구조는 웬만해서 인접리스트와 부모리스트로 구현하는 것이 맞음
graph = [[] for _ in range(n+1)]
parent = list(range(n+1))

# print(parent)

# 트리는 양방향 그래프의 일종이라고 봐도 됨
for _ in range(n-1):
    a, b = list(map(int, stdin.readline().split()))
    graph[a].append(b)
    graph[b].append(a)


def dfs(node, par):
    # 여기까지 왔다는건 제대로 된 부모-자식 관계라는 것
    parent[node] = par

    # 인접노드가 부모노드일 경우를 제외하고는 모두 재귀 호출
    for next_node in graph[node]:
        if next_node != par:
            dfs(next_node, node)

# dfs(1, 0) 호출만으로 모든 노드들의 parent정보를 알아낼 수 있음
dfs(1, 0)

# 처음에 'list' object is not callable 이런 오류가 떴었는데 이건 리스트를 함수처럼 ()으로 호출할때 발생하는 오류
for i in range(2, n+1):
    print(parent[i])


        


    

