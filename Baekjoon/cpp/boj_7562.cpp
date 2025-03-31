//boj_7562
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int t,a;
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {2,1,-1,-2,2,1,-1,-2};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> t;

    while(t--){
        pair<int,int> start;
        pair<int,int> end;

        cin >> a;
        bool vis[a][a];
        int dist[a][a];
        for(int i=0; i<a; i++){
            for(int j=0; j<a; j++){
                vis[i][j] = false;
                dist[i][j] = 0;
            }
        }
        cin >> start.X >> start.Y;
        cin >> end.X >> end.Y;
        
        if(((start.X == end.X)) && (start.Y == end.Y)){
            cout << 0 << "\n";
            continue;
        }

        queue<pair<int, int> > q;
        q.push({start.X,start.Y});
        vis[start.X][start.Y] = true;

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

             // 목표 지점에 도달하면 종료
            if (cur == end) {
                cout << dist[cur.X][cur.Y] << '\n';
                break;
            }

            for(int dir = 0; dir<8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(vis[nx][ny]) continue;
                if(nx < 0 || nx >= a || ny < 0 || ny >= a) continue;
                if(dist[nx][ny]) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }

        /* for(int i=0; i<a; i++){
            for(int j=0; j<a; j++){
                cout << dist[i][j] << " ";
            }
            cout <<"\n";
        } */


    }

}