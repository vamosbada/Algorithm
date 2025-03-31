//boj_15688
#include <bits/stdc++.h>
using namespace std;
int n;
int freq[2000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i <n; i++){
        int k;
        cin >> k;
        freq[k+1000000]++;
    }

    for(int i=0; i<=2000000; i++){
        while(freq[i]--){
            cout << i - 1000000 << "\n";
        }
    }
}