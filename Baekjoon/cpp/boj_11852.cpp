//boj_11852
#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int n;
int way[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[1] = 0;

    for(int i=2; i<=n; i++){

        dp[i] = dp[i-1] + 1;
        way[i] = i-1;
        if(i % 2 == 0 && dp[i] > dp[i/2]+1){
            dp[i] = dp[i/2] + 1;
            way[i] = i/2;
        }
        if(i % 3 == 0 && dp[i] > dp[i/3]+1){
            dp[i] = dp[i/3] + 1;
            way[i] = i/3;
        } 
    }

    cout << dp[n] << "\n";

    int curr = n;

    while(true){
        cout << curr << " ";
        if(curr==1) break;
        curr = way[curr];
    }
}