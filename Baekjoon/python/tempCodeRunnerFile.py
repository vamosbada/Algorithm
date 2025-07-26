from sys import stdin
n, m = map(int, stdin.readline().split())
nums = list(map(int, stdin.readline().split()))
result = []

def backtrack(seq, start):
    if len(seq) == m:
        result.append(seq[:])
        return
    
    for i in range(start, len(nums)):
        seq.append(nums[i])
        backtrack(seq, i+1)
        seq.pop()

backtrack([], 0)

tuple_results = [tuple(item) for item in result]
for val in list(dict.fromkeys(tuple_results)):
    print(val)