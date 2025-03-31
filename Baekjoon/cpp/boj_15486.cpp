//boj_15486
#include <bits/stdc++.h>
using namespace std;
int dp[1500003]; //수익의 합
int info[1500003][2]; //주어진 정보
int n; //날짜수


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> info[i][0] >> info[i][1];
    }

    for(int i=1; i<=n; i++){
        
        //날짜가 커지면 실행하지 않는다.
        if(i+info[i][0] <= n + 1){
            dp[i+info[i][0]] = max(dp[i+info[i][0]],dp[i]+info[i][1]); //해당 날짜의 수익이 상담을 했을 경우와 상담을 하지 않을 경우 기본 수익을 비교
        }
        
        //상담을 안하고 넘어갈 경우에 전날과 비교
        dp[i+1] = max(dp[i],dp[i+1]);

    }

    // for(int i=1; i<=n; i++){
    //     cout << dp[i] << " ";
    // }

    cout << dp[n+1];

}