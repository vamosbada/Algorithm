#include <bits/stdc++.h>
using namespace std;
int n;
int board[64][64];  // 최대 64x64 크기를 가정

void divide(int x, int y, int size) {
    bool isSame = true;
    int first_color = board[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (board[i][j] != first_color) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame) {
        cout << first_color;
    } else {
        int half = size / 2;
        cout << '(';
        divide(x, y, half);
        divide(x, y + half, half);
        divide(x + half, y, half);
        divide(x + half, y + half, half);
        cout << ')';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            board[i][j] = line[j] - '0';  // 문자를 정수로 변환
        }
    }

    divide(0, 0, n);  // 초기 영역 전체에 대해 재귀적 압축 시작
    cout << '\n';
    return 0;
}