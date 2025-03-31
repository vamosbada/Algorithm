//boj_2468
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int board[102][102];
bool vis[102][102];
bool isWater[102][102];
int n;
int max_area[102];
int max_h;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void reset(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            vis[i][j] = false;
            isWater[i][j] = false;
        }
    }

    // fill 함수 이용해서
    // for(int =0; i<n; i++){
    //     fill(vis[i],vis[i]+n,false);
    //     fill(isWater[i],isWater[i]+n,false);
    // } 처럼 채울 수 있음
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            max_h = max(board[i][j],max_h);
        }
    }

    for(int h=1; h<=max_h; h++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] <= h) isWater[i][j] = true;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] || isWater[i][j]) continue;
                queue <pair<int,int> > q;
                q.push({i,j});
                max_area[h]++;
                

                while(!q.empty()){
                auto cur = q.front();
                q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] || isWater[nx][ny]) continue;

                    q.push({nx,ny});
                    vis[nx][ny] = true;
                    }
        }

        }

    }
    reset(); //isWater랑 vis배열 초기화 함수
}

int result = *max_element(max_area,max_area+102);


if(result == 0) cout << 1 << "\n";
else cout << result  << "\n"; 

}