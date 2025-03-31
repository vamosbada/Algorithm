//boj_15349
#include <bits/stdc++.h>
using namespace std;
int dist[100003];
int n,k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    fill(dist,dist+100003,-1);

    dist[n] = 0;

    queue<int> q;
    q.push(n);

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        if(2*cur >= 0 && 2*cur <= 100000 && dist[2*cur] == -1) {
            dist[2*cur] = dist[cur];
            q.push(2*cur);
        }
        if(cur-1 >= 0 && cur-1 <=100000 && dist[cur-1] == -1) {
            dist[cur-1] = dist[cur] + 1;
            q.push(cur-1);
        }
        if(cur+1 >= 0 && cur+1 <= 100000 && dist[cur+1] == -1){
            dist[cur+1] = dist[cur] + 1;
            q.push(cur+1);
        } 
        
    }

    cout << dist[k] << "\n";

    return 0;


}