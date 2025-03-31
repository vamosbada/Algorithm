#include <bits/stdc++.h>
using namespace std;
int t;

int combination(int a,int b){
    vector<vector<int> > dp(a + 1, vector<int>(b + 1, 0));

    for(int i=0; i<=a; i++){
        for(int j=0; j<=min(i,b); j++){
            if(i==j || j==0){
                dp[i][j] = 1;
                continue;
            }
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[a][b];
}

int main(){
    
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m ;
        int answer = combination(m,n);
        cout << answer << "\n"; 
    }

}