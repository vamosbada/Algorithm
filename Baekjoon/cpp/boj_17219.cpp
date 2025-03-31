//boj_17219
#include <bits/stdc++.h>
using namespace std;
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    unordered_map <string,string> mp;
    while(n--){ 
    string s1;
    string s2;
    cin >> s1 >> s2;
    mp.insert(make_pair(s1,s2));
    }

    while(m--){
        string site;
        cin >> site;
        cout << mp[site] << "\n";
    }
}