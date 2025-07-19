def solution(word):
    words = []
    
    def dfs(current):
        words.append(current)  # ⭐ 전위순회: 현재 노드 먼저 처리!
        
        if len(current) == 5:  # 리프 노드
            return
            
        for vowel in ['A', 'E', 'I', 'O', 'U']:  # 자식들 순서대로
            dfs(current + vowel)
    
    dfs("")  # 빈 문자열부터 시작
    return words.index(word)  # 몇 번째인지 찾기

print(solution("A"))