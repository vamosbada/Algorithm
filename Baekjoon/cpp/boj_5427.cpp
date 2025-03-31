//백준 5427번
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1001];
int dist1[1001][1001];
int dist2[1001][1001];
int t;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t; 

    while(t--){
        int x,y;
        //행과 열을 입력받는다.
        cin >> x >> y;

        //보드를 입력받는다.
        for(int i=0; i<y; i++){
            cin >> board[i];
        }

        //거리를 초기화한다.
        for(int i=0; i<y; i++){
            fill(dist1[i],dist1[i]+x,-1);
            fill(dist2[i],dist2[i]+x,-1);
        }


        queue<pair<int,int> > q1;
        queue<pair<int,int> > q2;


        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                if(board[i][j] == '*'){
                    dist1[i][j] = 0;
                    q1.push({i,j});
                }
                if(board[i][j] == '@'){
                    dist2[i][j] = 0;
                    q2.push({i,j});
                }
            }
        }

        
        
        while(!q1.empty()){
            auto cur = q1.front();
            q1.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= y || ny < 0 || ny >= x ) continue;
                if(dist1[nx][ny] != -1) continue;
                if(board[nx][ny] == '#') continue;
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                q1.push({nx,ny});
            }
        }


        bool isEscaped = false;
        while(!q2.empty()){
            auto cur = q2.front();;
            //cout << cur.X << " " << cur.Y << "\n";
            q2.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                //cout << nx << " " << ny <<"\n";
                 if(nx < 0 || nx >= y || ny < 0 || ny >= x){
                    cout << dist2[cur.X][cur.Y] + 1 << "\n";
                    isEscaped = true;
                    break;
                }
                if(board[nx][ny] == '#') continue;
                if(dist2[nx][ny] != -1 || dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1) continue;
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                q2.push({nx,ny});
                //cout << nx << " "<< ny << "\n"; 
            }
            if(isEscaped) break;
        }

            /* for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
             cout << dist2[i][j] << " ";
            }
            cout << "\n";
        }  */

        if (!isEscaped) cout << "IMPOSSIBLE\n";

    }

    
}