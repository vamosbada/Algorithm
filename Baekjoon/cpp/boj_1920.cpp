//boj_1920번
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    unordered_set<int> set_n;
    int number;
    for (int i = 0; i < n; i++) {
        cin >> number;
        set_n.insert(number);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> number;
        if (set_n.find(number) != set_n.end())
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}