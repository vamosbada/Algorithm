//boj_2447
#include <bits/stdc++.h>
using namespace std;
char board[2300][2300];

void solve(int size,int x,int y){
    if(size == 1) {
        board[x][y] = '*';
        return;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==1 && j==1) continue;
            solve(size/3,x+(size/3)*i,y+(size/3)*j);
        }
    }
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        fill(board[i],board[i]+n,' ');
    }

    solve(n,0,0);

    for(int i=0; i<n; i++){
        cout << board[i] << "\n";
    }


}