//boj_17298j
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int result[1000005];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(result,result+1000005,-1);
    stack<int> S;

    cin >> n ;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    for(int i=n; i>=1; i--){
        int val = a[i];

        while(!S.empty() && val >= S.top()){
            S.pop();
        }

        if(S.empty()) {
            S.push(val);
            continue;
        }
        else {
            result[i] = S.top();
            S.push(val);
        }
    }

    for(int i=1; i<=n; i++){
        cout << result[i] << " ";
    }
 
}