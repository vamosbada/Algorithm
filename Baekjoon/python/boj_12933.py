# sol1  = 계수정렬
def solution(n):
    result = ""
    count = [0 for _ in range(10)]
    for c in str(n):
        # ord() = 아스키코드값으로 바꿈, chr() = 아스키값을 문자로 바꿈
        count[ord(c) - ord("0")] += 1
    for i in range(9, -1, -1):
        result += count[i] * chr(i + ord('0'))
    return int(result)

# sol2 = 내장함수 사용
def solution(n):
    ls = list(str(n))
    ls.sort(reverse = True)
    return int("".join(ls))

# 핵심 아이디어 : 둘다 큰 숫자를 다루기 위해 이것을 문자열로 다뤘음, 숫자 자체를 사용해야되는 것이 아니라면 문자열로 사용하는 것을 고려


print(solution(118372))

