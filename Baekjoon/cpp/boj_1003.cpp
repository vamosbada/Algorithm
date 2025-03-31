//boj_1003
#include <bits/stdc++.h>
using namespace std;
int t;

struct Howmany {
    int zero;
    int one;
};

struct Howmany fibonacci(int n){

    struct Howmany dp[100000];
    dp[0].zero = 1;
    dp[0].one = 0;
    dp[1].zero = 0;
    dp[1].one = 1;
 
    for(int i=2; i<=n; i++){
       dp[i].zero = dp[i-2].zero + dp[i-1].zero;
       dp[i].one = dp[i-2].one + dp[i-1].one;
    }

    return dp[n];

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--){
        int n;
        cin >> n;
        struct Howmany answer = fibonacci(n);
        cout << answer.zero << " " <<  answer.one << "\n";
    }
}
