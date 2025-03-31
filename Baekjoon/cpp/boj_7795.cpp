//백준 7795번
#include <bits/stdc++.h>
using namespace std;
int t;
int x,y;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--){
        cin >> x >> y;
        vector<pair<int,int> > v;

        for(int i=0; i<x; i++){
            int p;
            cin >> p;
            v.push_back({p,0});
        }

        for(int i=0; i<y; i++){
            int p;
            cin >> p;
            v.push_back({p,1});
        }

        sort(v.begin(),v.end());

        int ans = 0;
        int cnt = 0;

        for(int i=0; i<v.size(); i++){
            if(v[i].second == 0){
            ans += cnt;
            }
            else cnt++;
        }

        cout << ans << "\n";
        
    }

}