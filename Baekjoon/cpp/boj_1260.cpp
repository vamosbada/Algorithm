//boj_1260
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int v;
int board[1001][1001];
bool vis[1001];
queue <int> q;

void reset(){
    for(int i=1; i<=n; i++){
        vis[i] = false;
    }
}

void dfs(int v){
    vis[v] = true;
    cout << v << " ";

    for(int i=1; i<=n; i++){
        if(board[v][i] == 1 && !vis[i]){
            dfs(i);
        }
    }
}

void bfs(int v){
    cout << v << " ";
    q.push(v);
    vis[v] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(board[curr][i] == 1 && !vis[i]){
                vis[i] = true;
                q.push(i);
                cout << i << " ";
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> v;

   while(m--){
    int a = 0;
    int b = 0;
    cin >> a >> b;
    board[a][b] = 1;
    board[b][a] = 1;
   }


    dfs(v);
    reset();

    cout << "\n";

    bfs(v);

}