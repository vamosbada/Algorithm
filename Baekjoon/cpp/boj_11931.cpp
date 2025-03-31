//백준 11931번
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000001];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a,a+n,greater<int>());

    for(int i=0; i<n; i++){
        cout << a[i] << "\n";
    }

}