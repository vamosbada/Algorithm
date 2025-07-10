def solution(phone_book):
    phone_book.sort() # 파이썬의 sort의 시간복잡도는 O(nlogn)

    for i in range(1, len(phone_book)):
        if phone_book[i].startswith(phone_book[i-1]): # startswith는 접두어인지 판별하는 함수
            return False
    return True

print(solution(["119", "97674223", "1195524421"]))