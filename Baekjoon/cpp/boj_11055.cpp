//boj_11055
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1002];
int d[1002];


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    d[1] = a[1];

    for(int i=2; i<=n; i++){
        int max_val=0;
        
        for(int j=i-1; j>=1; j--){
            if(a[j] < a[i]){
             max_val =max(d[j],max_val);
            }
        }
        d[i] = a[i] + max_val;
    }

    int ans = *max_element(d+1,d+n+1);

    //  for(int i=1; i<=n; i++){
    //     cout<<  d[i] << " ";
    // }

    cout << ans;



}
