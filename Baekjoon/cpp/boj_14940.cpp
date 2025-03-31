//boj_14940
#include <bits/stdc++.h>
using namespace std;
int n,m;
int board[1001][1001];
bool vis[1001][1001];
int result[1001][1001];
int dis;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
#define X first
#define Y second

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    pair<int,int> start_point;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            board[i][j] = x;
            if(x==2) {
               start_point = make_pair(i,j);
            }
        }
    }

    queue<pair<int,int> > q;

    q.push(start_point);
    vis[start_point.X][start_point.Y] = true;



    while(!q.empty()){
        pair<int,int> curr = q.front();

        for(int i=0; i<4; i++){
        int dir_x = curr.X + dx[i];
        int dir_y = curr.Y + dy[i];

        if(dir_x < 0 || dir_x >= n || dir_y < 0 ||  dir_y >= m) continue;
        if(vis[dir_x][dir_y] ||board[dir_x][dir_y] == 0) continue;
        
        result[dir_x][dir_y] = result[curr.X][curr.Y] + 1;
        vis[dir_x][dir_y] = true;
        q.push(make_pair(dir_x,dir_y));
        }
        q.pop();
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && board[i][j] == 1) {
                cout << -1 << " ";
                continue;
            }
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}

