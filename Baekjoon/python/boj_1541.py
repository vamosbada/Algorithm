from sys import stdin
string = stdin.readline().rstrip()
split_minus = string.split('-')

lst = []
for s in split_minus:
    lst.append(int(sum(map(int, s.split('+')))))

# 파이썬스러운 전체 요소 빼기 연산
answer = lst[0] - sum(lst[1:])

print(answer)