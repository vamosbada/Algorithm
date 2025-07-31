from sys import stdin
from collections import defaultdict

t = int(stdin.readline().rstrip())

while(t > 0):
    t -= 1
    n = int(stdin.readline().rstrip())
    # defaultdict는 반드시 초기값을 줘야 함
    clothes_type = defaultdict(int)
    for _ in range(n):
        name, type = stdin.readline().split()
        clothes_type[type] += 1

    answer = 1
    # 처음에 combination을 썼다가 메모리 초과가 뜸
    # 30가지가 서로 다른 종류라고 했을 때 입을 경우 안 입을 경우를 하면 2^30이 되므로 메모리 초과
    for count in clothes_type.values():
        answer *= (count + 1)  # 각 종류별로 (개수+1) 곱하기
    
    answer -= 1  # 아무것도 안 입는 경우 제외
    print(answer)