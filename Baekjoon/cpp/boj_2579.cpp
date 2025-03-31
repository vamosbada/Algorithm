//boj_2579
#include <bits/stdc++.h>
using namespace std;
int n;
int dp[500][3];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int num[n+1];

    for(int i=1; i<=n; i++){
        cin >> num[i];
    }

    dp[2][1] = num[2];
    dp[1][1] = num[1];
    dp[2][2] = num[1]+num[2];
    
    for(int i=3; i<=n; i++){
        dp[i][2] = dp[i-1][1] + num[i];
        dp[i][1] = max(dp[i-2][2],dp[i-2][1]) + num[i];
    }

    cout << max(dp[n][1],dp[n][2]);

}