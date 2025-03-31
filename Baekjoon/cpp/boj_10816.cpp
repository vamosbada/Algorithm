//boj_10816
#include <bits/stdc++.h>
using namespace std;
int n,m;
int num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    unordered_map<int,int> hashtable;
    
    for(int i=0; i<n; i++){
        cin >> num;
        hashtable[num]++;
    }

    cin >> m;
    for(int i=0; i<m; i++){
        cin >> num;
        cout << hashtable[num] << " ";
    }
}
