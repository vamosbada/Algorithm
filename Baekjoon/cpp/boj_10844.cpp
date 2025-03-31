//boj_10844
#include <bits/stdc++.h>
using namespace std;
int dp[103][11];
int n;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;

    for(int i=1; i<10; i++){
        dp[1][i] = 1;
    }


    for(int i=2; i<=n; i++){
        for(int k=0; k<10; k++){
            if(k == 0){
                dp[i][k] = dp[i-1][1];
            } else if(k == 9){
                dp[i][k] = dp[i-1][8];
            } else {
                dp[i][k] = (dp[i-1][k-1] + dp[i-1][k+1]) % 1000000000;
            }
    }
    }

    int result = 0;
    for(int i=0; i<10; i++){
        result = (result + dp[n][i])%1000000000;
    }

    cout << result << "\n";
}