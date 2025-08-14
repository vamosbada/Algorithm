from sys import stdin

# 입력 받기
n = int(stdin.readline())  # 찾아야 할 P_N의 N
m = int(stdin.readline())  # 문자열 S의 길이
s = stdin.readline().rstrip()  # 문자열 S

count = 0    # 연속으로 발견한 IOI 패턴의 개수
result = 0   # P_N 패턴을 찾은 총 개수

i = 0
while i < m - 2:  # 3글자를 확인하므로 m-2까지만
   if s[i:i+3] == 'IOI':  # IOI 패턴 발견
       count += 1         # 연속 패턴 개수 증가
       
       if count >= n:     # 충분한 길이의 연속 패턴이 만들어짐
           result += 1    # P_N을 하나 더 만들 수 있음
           
       i += 2  # IOI의 마지막 I가 다음 IOI의 첫 번째 I가 됨 (겹침 처리)
   else:
       count = 0  # IOI 패턴이 끊어짐, 카운트 초기화
       i += 1     # 다음 문자로 이동

print(result)