//boj_1932
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[505][505];
int dp[505][505];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];
    if(n==1) {
        cout << dp[1][1];
        return 0;
    }

    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + arr[i][j];
        }
    }

    cout << *max_element(dp[n],dp[n]+n+1);

}
