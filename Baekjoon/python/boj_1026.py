from sys import stdin
n = stdin.readline().rstrip()
a = list(map(int, stdin.readline().split()))
a.sort()
b = list(map(int, stdin.readline().split()))
b.sort(reverse=True)

# 결국 a의 최대 * b의 최소의 합들을 원하는 것이므로 정렬, 역정렬들의 요소곱의 합
print(sum(x * y for x, y in zip(a, b)))