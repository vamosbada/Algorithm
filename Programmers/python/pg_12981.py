def solution(n, words):
    loop_cnt = 1
    person = 1
    # words_set = set(words[0]) set에 iterable한 객체를 던져주면 요소들로 분해해서 저장한다.
    # words_set = set([words[0]]) 로 하든가 아래처럼 해야됨
    words_set = {words[0]}

    for i in range(1, len(words)):
        person += 1
        if person > n: 
            loop_cnt += 1
            person = 1
        if words[i] in words_set or words[i-1][-1] != words[i][0]: return [person, loop_cnt]
        words_set.add(words[i])
    return [0, 0]

print(solution(3,["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"]))