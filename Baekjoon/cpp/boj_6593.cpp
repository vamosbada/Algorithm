//boj_6593
#include <bits/stdc++.h>
using namespace std;
int l,r,c;
char board[33][33][33];
int dist[33][33][33];
int dh[6] = {1,0,0,-1,0,0};
int dx[6] = {0,0,1,0,0,-1};
int dy[6] = {0,-1,0,0,1,0};
int goal_l,goal_r,goal_c;


void reset(){
    for(int i=0; i<l; i++){
        for(int j=0; j<r; j++){
            for(int k=0; k<c; k++){
                dist[i][j][k] = -1;
            }
        }
    }
    goal_l = 0;
    goal_r = 0;
    goal_c = 0;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> l >> r >> c;
        if(l+r+c == 0) return 0;

        reset();
        
        queue <tuple<int,int,int> > q;

        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                string s;
                cin >> s;
                    for(int k=0; k<c; k++){
                        board[i][j][k] = s[k];
                        if(s[k] == 'S') {
                            q.push({i,j,k});
                            dist[i][j][k] = 0;
                        }
                        if(s[k] == 'E') {
                            goal_l = i;
                            goal_r = j ;
                            goal_c = k;
                        }
                    }
            }
        }
        // cout << goal_l << " " << goal_r << " " << goal_c << "\n";

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            for(int dir=0; dir<6; dir++){
                int nh = get<0>(cur) + dh[dir];
                int nx = get<1>(cur) + dx[dir];
                int ny = get<2>(cur) + dy[dir];

                if(nh < 0 || nh >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(board[nh][nx][ny] == '#' || dist[nh][nx][ny] > 0) continue;
                
                dist[nh][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
                q.push({nh,nx,ny});
            }
        }
        
        if(dist[goal_l][goal_r][goal_c] > 0) cout << "Escaped in" << " " << dist[goal_l][goal_r][goal_c] << " " << "minute(s)." << "\n";
        else cout << "Trapped!" << "\n";

    }


}

