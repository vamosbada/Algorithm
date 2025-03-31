#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int a[500001]; // 입력 최대 500,000개를 고려
int how_many[8001]; // 인덱스 0~8000 (4000으로 오프셋 조정)
int n;
int new_a[500001]; // 최대 500,000개

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        how_many[a[i] + 4000]++;
    }

    copy(a, a + n, new_a);
    sort(new_a, new_a + n);

    double avg = accumulate(a, a + n, 0.0) / n;
    if (round(avg) == -0.0){
        cout << 0.0 << "\n";
    }else {
        cout << round(avg) << "\n";  // 산술평균
    }

    cout << new_a[(n-1)/2] << "\n";  // 중앙값

    vector<int> modes;
    int max_freq = 0;
    for(int i = 0; i < 8001; i++) {
        if (how_many[i] > max_freq) {
            max_freq = how_many[i];
        }
    }
    for(int i = 0; i < 8001; i++) {
        if(how_many[i] == max_freq) {
            modes.push_back(i - 4000);
        }
    }

    if(modes.size() > 1) {
        sort(modes.begin(), modes.end());  // 최빈값이 여러 개일 경우 정렬
        cout << modes[1] << "\n";  // 두 번째로 작은 최빈값 출력
    } else {
        cout << modes[0] << "\n";  // 하나만 있을 경우 그 값을 출력
    }

    cout << new_a[n-1] - new_a[0] << "\n";  // 범위

    return 0;
}