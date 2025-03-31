//boj_11728
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int b[1000005];


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);

    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    sort(b,b+m);

    int aidx = 0;
    int bidx = 0;

    for(int i=0; i<n+m; i++){

        if(aidx == n){
            while(1){
                cout << b[bidx++] << " ";
                if(bidx==m) break;
            }
            break;
        }
        if(bidx == m){
            while(1){
                cout << a[aidx++] << " ";
                if(aidx==n) break;
            }
            break;
        }

        if(a[aidx] <= b[bidx]){
            cout << a[aidx++] <<" ";
        }
        else {
            cout << b[bidx++] <<" ";
        }
    }

}
