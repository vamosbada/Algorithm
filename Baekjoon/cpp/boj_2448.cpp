#include <bits/stdc++.h>
using namespace std;
char board[3500][7000];
int n;
int k;

void print_star(int x,int y){
    board[x][y] = '*';
    board[x+1][y-1] = '*';
    board[x+1][y+1] = '*';
    
    for(int i=0; i<5; i++){
        board[x+2][y-2+i] = '*';
    }
}

void star(int depth,int x,int y,int size){
    if(depth==0){
        print_star(x,y);
        return;
    }

    depth--;
    int newsize = size/2;
    star(depth,x,y,newsize);
    star(depth,x+newsize,y-newsize,newsize);
    star(depth,x+newsize,y+newsize,newsize);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    k = log2(n / 3);

    for(int i=0; i<n; i++){
        fill(board[i],board[i]+(2*n-1),' ');
    }

    star(k,0,n-1,n);

    for(int i=0; i<n; i++){
        cout << board[i] << "\n";
    }

}