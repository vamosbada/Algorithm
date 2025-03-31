//백준 10026번
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
char board[101][101];
//정상보드 방문여부
bool vis_n[101][101];
//비정상보드 방문여부
bool vis_a[101][101];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};


void normal_RGB(char board[101][101]){

    stack<pair<int,int> > st;
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //시작점이 과거에 방문했으면 continue
            if(vis_n[i][j]) continue;
            //cout << "normal_RGB 시작, 현재 i: " << i << ", j: " << j << endl;
            //방문 안했으면 방문처리 하고 dfs
            vis_n[i][j] = true;
            st.push(make_pair(i,j));
            //cout << "스택에 추가됨" << i << j << "색" << board[i][j] << "\n";
            cnt++;
            char first_point = board[i][j];
            while(!st.empty()){
                //cout << "스택의 크기" << st.size() << "\n";
                pair<int,int> cursor = st.top(); 
                st.pop();
                for(int dir = 0; dir<4; dir++){
                    int nx = cursor.X + dx[dir];
                    int ny = cursor.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] != first_point) continue;
                    if(vis_n[nx][ny]) continue;
                    vis_n[nx][ny] = true;

                    st.push(make_pair(nx,ny));
                    //cout << "새로 들어간 좌표 " <<  nx << " " << ny << "\n";
                }
            }
        }
    }

    cout<< cnt << " ";
}

void abnormal_RGB(char board[101][101]){
    stack<pair<int,int> > st;
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //시작점이 과거에 방문했으면 continue
            if(vis_a[i][j]) continue;
            //방문 안했으면 방문처리 하고 dfs
            vis_a[i][j] = true;
            st.push(make_pair(i,j));
            cnt++;
            char first_point = board[i][j];
            while(!st.empty()){
                pair<int,int> cursor = st.top(); st.pop();
                for(int dir = 0; dir<4; dir++){
                    int nx = cursor.X + dx[dir];
                    int ny = cursor.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(((first_point == 'R') || (first_point == 'G')) && (board[nx][ny] == 'B') ) continue;
                    if((first_point == 'B') && (first_point != board[nx][ny])) continue;
                    if(vis_a[nx][ny]) continue;
                    vis_a[nx][ny] = true;
                    st.push(make_pair(nx,ny));
                }
            }
        }
    }

    cout<< cnt << " ";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //n 입력받음
    cin >> n;

    //보드 설정
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            board[i][j] = s[j];
        }
    }

    normal_RGB(board);
    abnormal_RGB(board);

    return 0;

}