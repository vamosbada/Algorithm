//백준 5648번
#include <bits/stdc++.h>
using namespace std;
int n;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    long long a[n];

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        reverse(s.begin(),s.end());
        a[i] = stoll(s);
    }
    sort(a,a+n);

    for(int i=0; i<n; i++){
        cout << a[i] << "\n";
    }

    return 0;
}