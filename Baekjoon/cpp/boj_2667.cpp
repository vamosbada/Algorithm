//boj_2667
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
bool vis[26][26]; //왔다감 배열
int board[26][26]; //집 존재여부 배열
int n; //보드의 크기
int cnt; //단지수
int house[630]; //단지별 집의 개수
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int j=0;
        for(auto c:s){
            board[i][j] = c - '0';
            j++;
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout <<board[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }
    

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] && !vis[i][j]){

                queue<pair<int,int> > q;
                q.push({i,j});
                vis[i][j] = true;
                cnt++;
                house[cnt]++;
            
                while(!q.empty()){
                    auto cur = q.front();
                    vis[cur.X][cur.Y] = true;
                    q.pop();
            
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx > n || ny < 0 || ny > n) continue;
                        if(!board[nx][ny]|| vis[nx][ny])continue;
                        house[cnt]++;
                        vis[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }

    cout << cnt << "\n";

    if(cnt == 0) return 0;
    
    sort(house,house+cnt+1);

    for(int i=0; i<=cnt; i++){
        if(house[i] == 0) continue;
        else cout << house[i] << "\n";
    }


}