#include <bits/stdc++.h>
using namespace std;
bool vis[1000002];
int min_cnt[1000002];
int full;
int start;
int goal;
int up;
int down;
int cnt;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> full >> start >> goal >> up >> down;

    //start랑 goal이랑 같으면 0 출력
    if(start == goal){
        cout << 0 << "\n";
        return 0;
    }

    queue <int> q;
    q.push(start); 
    vis[start] = true;


    while(!q.empty()){
        int cur = q.front();
        int cnt = min_cnt[cur]+1;
        q.pop();
        int n1 = cur + up;
        int n2 = cur - down;
        if(n1 <= full && !vis[n1]) {
            q.push(n1);
            vis[n1] = true;
            min_cnt[n1] = cnt;
        }
        if(n2 >= 1 && !vis[n2]) {
            q.push(n2);
            vis[n2] = true;
            min_cnt[n2] = cnt;
        }
    }

    // for(int i=goal; i>=1; i--){
    //     cout << min_cnt[i] << "\n";
    // }

    if(min_cnt[goal] == 0) cout << "use the stairs";
    else cout << min_cnt[goal];




}