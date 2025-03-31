//boj_11652
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    map <ll , int> mp;

    while(n--){
        ll x;
        cin >>x;
        mp[x]++;
    }

    int mx_value = 0;
    ll mx_key;

    for(auto &it : mp){
        if(it.second > mx_value){
            mx_key = it.first;
            mx_value = it.second;
        }
    }

    cout << mx_key;
}