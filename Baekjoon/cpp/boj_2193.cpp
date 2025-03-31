//백준 2193번
#include <bits/stdc++.h>
using namespace std;
long long d[91];
long long a[91]; //시작이 1이고 끝이 0인 이친수
long long b[91]; //시작이 1이고 끝이 1인 이친수
int n;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    a[1] = 0;
    b[1] = 1;

    for(int i=2; i<=n; i++){
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }

    d[n] = a[n] + b[n];

    cout << d[n];
    
}