from sys import stdin
n = int(stdin.readline().rstrip())
meeting = []

for _ in range(n):
    a, b = map(int, stdin.readline().split())
    meeting.append((a, b))

# key 함수는 sort할 인자들을 받아 하나의 값으로 반환
# 이때 x를 (x[1], x[0])이라는 튜플형태로 반환함으로써서 x[1] 오름차순(같을 때는 x[0] 오름차순)으로 정렬함
meeting.sort(key = lambda x : (x[1], x[0]))

cnt = 0
t = 0

for time in meeting:
    if t <= time[0]:
        t = time[1]
        cnt += 1

print(cnt)
