//boj_11727
#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1005][3];

int main(){

    cin >> n;

    dp[1][1] = 1;
    dp[1][0] = 0;
    dp[1][2] = 0;
    dp[2][1] = 1;
    dp[2][0] = 1;
    dp[2][2] = 1;



    for(int i=3; i<=n; i++){
       dp[i][0] = (dp[i-2][1] + dp[i-2][0] + dp[i-2][2])%10007;
       dp[i][1] = (dp[i-1][1] + dp[i-1][0] + dp[i-1][2])%10007;
       dp[i][2] = (dp[i-2][1] + dp[i-2][0] + dp[i-2][2])%10007;
    }
    
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 10007;
}