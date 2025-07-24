def solution(numbers):
    # 핵심 아이디어: 각 숫자를 10번 반복한 문자열을 키로 사용
    # 예: 3 -> "3333333333", 30 -> "3030303030"
    # 이렇게 하면 사전순 정렬만으로도 "가장 큰 수"를 만드는 순서가 나옴
    sorted_nums = sorted(
        numbers, 
        key=lambda x: str(x) * 10,  # 정렬 기준: 각 숫자를 10번 반복한 문자열
        reverse=True                # 내림차순 정렬 (큰 것부터)
    )
    
    # 정렬된 숫자들을 문자열로 변환해서 이어붙이기
    answer = ''.join(map(str, sorted_nums))
    
    # 특수 케이스: 모든 숫자가 0인 경우 "000..." 대신 "0" 반환
    return '0' if answer[0] == '0' else answer

print(solution([6, 10, 2]))
print(solution([3, 30, 34, 5, 9]))