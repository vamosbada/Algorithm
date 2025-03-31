//boj_6198
#include <bits/stdc++.h>
using namespace std;
int n,h;
long long cnt;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    stack<int> S;


    while(n--){
       cin >> h;

       while(!S.empty() && S.top() <= h){
        S.pop();
       }
       cnt += S.size();

       S.push(h);
    }

    cout << cnt;
    
}