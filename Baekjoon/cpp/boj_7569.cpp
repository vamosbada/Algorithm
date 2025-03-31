//백준 7569번
#include <bits/stdc++.h>
using namespace std;
int m,n,h;
int dist[101][101][101];
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,0,1,0,0,-1};
int dz[6] = {0,1,0,0,-1,0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;
    int board[m][n][h];
    queue<tuple<int,int,int> > q;

    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> board[j][i][k];
                if(board[j][i][k] == 0){
                    dist[j][i][k] = -1;
                }
                if(board[j][i][k] == 1){
                    q.push(make_tuple(j,i,k));
                    //cout << "튜플에 들어가는 값은 " << j << i << k<<"\n";
                }
            }
        }
    }

    /*for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << board[j][i][k]; 
            }
            cout << "\n";
        }
    } */

                while(!q.empty()){
                    auto cur = q.front();
                    //cout << get<0>(cur) << get<1>(cur) << get<2>(cur) << "\n";
                    q.pop();
                    for(int dir=0; dir<6; dir++){
                        int nx = get<0>(cur) + dx[dir];
                        int ny = get<1>(cur) + dy[dir];
                        int nz = get<2>(cur) + dz[dir];
                        if(nx<0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
                        if(board[nx][ny][nz] == -1 || board[nx][ny][nz] == 1) continue;
                        board[nx][ny][nz] = 1;
                        dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                        q.push(make_tuple(nx,ny,nz));
                    }
                }
            
        int ans = 0;
        for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dist[j][i][k] == -1){
                    cout << -1;
                    return 0;
                }
                ans = max(ans,dist[j][i][k]);
            }
        }
    }
    
        cout << ans;

}