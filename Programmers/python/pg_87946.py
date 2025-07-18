def solution(k, dungeons):
    max_count = 0  
    visited = [False] * len(dungeons) # 리스트 컴프리헨션으로 처리해도 됨
    
    def backtrack(hp, count):
        # global = 최상위, nonlocal = 바로 바깥
        nonlocal max_count
        # 매번 최댓값을 갱신할지 비교
        max_count = max(max_count, count) 
        
        # 순서가 중요한게 아니라 결국 최대한 돌아야되므로 모든 던전 순회
        for i in range(len(dungeons)):
            # 방문하지 않았거나 현재 hp가 입구컷보다 높아야됨. hp가 0 이하일 필요가 여기에 포함관계임
            if not visited[i] and hp >= dungeons[i][0]:
                # true로 바꾸고 재귀를 돌리고 다시 false로 바꿈으로써 마치 방문하지 않은 것처럼 리셋
                visited[i] = True
                backtrack(hp - dungeons[i][1], count + 1)
                visited[i] = False
    
    backtrack(k, 0)
    return max_count

print(solution(80, [[80,20],[50,40],[30,10]]))
