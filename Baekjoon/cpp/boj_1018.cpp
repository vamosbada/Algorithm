//boj_1018번
#include <bits/stdc++.h>
using namespace std;
int n,m;
char board[52][52];
int small = INT_MAX;

int changeColor(int a,int b,char c){
    int cnt = 0;
    char first_color = c;
    char expected_color;
    
    for(int i=a; i<a+8; i++){
        for(int j=b; j<b+8; j++){
           expected_color = ((i+j)%2==0) ? first_color : (first_color == 'W' ? 'B' : 'W');
           if(expected_color != board[i][j]) cnt++;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i <= n-8; i++){
        for(int j=0; j<= m-8; j++){
            small = min(small,changeColor(i,j,'W'));
            small = min(small,changeColor(i,j,'B'));
        }
    }
    
    cout << small << "\n";
}


