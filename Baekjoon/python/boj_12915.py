def solution(strings, n):
    # 파이썬의 정렬은 두 가지 방식이 있음(둘다 key로 람다함수 사용가능)
    # sort = 반환형 없음, sorted = 정렬된 것이 반환됨
    # 기본적으로 둘다 stable sort여서 string[n]에 따라 정렬하다가 이 값이 같으면 원래 상태를 보장함
    # 따라서 string[n]이 같을때 사전순으로 정렬하고 싶으면 1번째 인자가 같으면 2번째 인자를 비교하는 튜플정렬을 사용해야됨
    return sorted(strings, key = lambda string : (string[n], string))

print(solution(["sun", "bed", "car"], 1))
print(solution(["abce", "abcd", "cdx"], 2))