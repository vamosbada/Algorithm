def solution(enroll, referral, seller, amount):
    parent = dict(zip(enroll, referral)) # zip은 튜플형태를 반환함
    total = {name : 0 for name in enroll}
    for i in range(len(seller)):
        money = amount[i] * 100
        cur_name = seller[i]

        while money > 0 and cur_name != '-':
            total[cur_name] += money - money//10 # 10원미만은 다루지 않으므로 /가 아닌 //으로 사용
            cur_name = parent[cur_name]
            money //= 10
    return [total[name] for name in enroll]