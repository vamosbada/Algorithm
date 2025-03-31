def solution(id_list, report, k):
    who_report = {name : [] for name in id_list}
    reported_numbers = {name : 0 for name in id_list}
    for text in report:
        text = text.split()
        if text[1] not in who_report[text[0]]:
            who_report[text[0]].append(text[1])
            reported_numbers[text[1]] += 1
    
    banned_list = []
    for name in reported_numbers:
        if reported_numbers[name] >= k:
            banned_list.append(name)
    
    answer = []
    for name in who_report:
        intersection = set(who_report[name]) & set(banned_list)
        answer.append(len(intersection))
    
    return answer

id_list = ["muzi", "frodo", "apeach", "neo"]
report = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
k = 2
print(solution(id_list, report, k))

id_list = ["con", "ryan"]
report = ["ryan con", "ryan con", "ryan con", "ryan con"]
k = 3
print(solution(id_list, report, k))


