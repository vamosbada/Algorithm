//boj_2583
#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 
int m,n;
bool vis[101][101];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool isPainted[101][101];
int box;
int cnt;
int area[1000];


int main(){
    
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    //보드의 크기와 박스의 숫자 입력받음
    cin >> m >> n >> box;

    // cout << m << n << box << "\n";

    
    //박스의 크기에 따라 좌표를 입력받고 보드를 색칠
    while(box--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int i=b; i<d; i++){
            for(int j=a; j<c; j++){
                isPainted[i][j] = true;
                vis[i][j] = true; 
            }
        }
    }

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout << isPainted[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    queue<pair<int,int> > q;

    //보드 한 바퀴를 돌면서 시작점을 찾음
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            //색칠이 되어있거나 이미 방문했으면 건너뛴다.
            if(isPainted[i][j]|| vis[i][j]) continue;
            
            //색칠이 안되어있거나 방문 안했으면 큐에 넣는다.
            q.push({i,j});
            cnt++;
            vis[i][j] = true;

            while(!q.empty()){
            auto cursor = q.front();
            // cout << cursor.first << cursor.second << endl;
            q.pop();
            area[cnt]++;
            for(int dir=0; dir<4; dir++){
                int nx = cursor.X + dx[dir];
                int ny = cursor.Y + dy[dir];
                //x는 행, y는 열을 의미한다.
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(isPainted[nx][ny] || vis[nx][ny]) continue;
                vis[nx][ny] = true;
                q.push({nx,ny});
                }
            }

        }
    }

    cout << cnt << "\n";

    //오름차순으로 정렬
    sort(area+1,area+cnt+1);

    for(int i=1; i<=cnt; i++){
        cout <<area[i] << " ";
    }
  
 
}
/*
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
*/