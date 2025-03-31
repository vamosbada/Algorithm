//boj_11053
#include <bits/stdc++.h>
using namespace std;
int a[1002];
int d[1002];
int n;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    d[1] = 1;

    for(int i=2; i<=n; i++){
        int max_val = 0;
        for(int j=i-1; j>=1; j--){
            if(a[i] > a[j]){
                max_val = max(max_val,d[j]);
            }
        }
        if(max_val == 0) d[i] = 1;
        else d[i] = max_val + 1;
    }

    //  for(int i=1; i<=n; i++){
    //     cout <<  d[i] << " ";
    // }


    int result = *max_element(d+1,d+n+1);

    cout << result;

}
