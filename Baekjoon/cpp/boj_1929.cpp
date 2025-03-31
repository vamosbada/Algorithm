//boj_1929
#include <bits/stdc++.h>
using namespace std;
int m,n;
int arr[1000001] = {1,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i=2; i<=n; i++){
        arr[i] = i;
    }

    for(int i=2; i*i <= n; i++){
        
        for(int j=i*i; j<=n; j+=i)
            arr[j] = 1;
        }
    
    for(int i=m; i<=n; i++){
        if(arr[i] != 1) cout << arr[i] << "\n";
       }
    
}