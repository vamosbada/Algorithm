//boj_11047
#include <bits/stdc++.h>
using namespace std;
int n,k;
int quotient;
int cnt;

int main(){

    cin >> n >> k;
    int money[n];
    
    for(int i=0; i<n; i++){
        cin >> money[i];
    }

    for(int i=n-1; i>=0; i--){
        if(money[i] > k) continue;
        else {
            quotient = k / money[i];
            cnt += quotient;
            k = k % money[i];
            if(k==0) break;
        }
    }

    cout << cnt;

}