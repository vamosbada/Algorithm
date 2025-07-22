def solution(array, commands):
    answer = []
    def func(lst):
        i, j, k = lst
        # 파이썬 slice는 새로운 객체를 생성, slice[a,b]는 인덱스 a부터 b-1까지 슬라이스
        return sorted(array[i-1:j])[k-1]
    for command in commands:
        answer.append(func(command))
    return answer

print(solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]]))