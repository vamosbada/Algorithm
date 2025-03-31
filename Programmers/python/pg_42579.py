def solution(genres, plays):
    # 노래들을 고유 번호에 맞춰서 저장함
    song = { i : [genres[i], plays[i]] for i in range(len(genres))}
    # 노래들을 재생수로 내림차순 정렬함
    song_sorted = sorted(song.items(), key=lambda item : item[1][1], reverse=True)
    # 각 장르별로 몇 번 들었는지 저장하고 내림차순으로 정렬함
    best_genres = {}
    for i,(genre, play) in song_sorted:
        best_genres[genre] = best_genres.get(genre, 0) + play
    best_genres_sorted = sorted(best_genres.items(), key=lambda item: item[1], reverse=True)

    # 장르별로 두 곡씩 뽑아내지만 해당 장르곡이 하나밖에 없을 경우 그것만 출력하고 아님 두 개씩 뽑아냄
    answer = []
    for genre, _ in best_genres_sorted:
        cnt = 0
        for idx, (song_genre, _) in song_sorted:
            if genre == song_genre:
                answer.append(idx)
                cnt+=1
            if cnt == 2: break

    return answer

genres = ["classic", "pop", "classic", "classic", "pop"]
plays = [500, 600, 150, 800, 2500]
print(solution(genres, plays))