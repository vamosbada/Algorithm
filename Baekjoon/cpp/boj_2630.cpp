//백준 2630번
#include <bits/stdc++.h>
using namespace std;

int n;
int board[130][130];
int total;
int divide;
int blue,white;

int paper(int a,int b,int size){
    int first_color = board[a][b];
    bool same = true;

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(board[a+i][b+j] != first_color){
             same = false;
             break;
        }
    }
    if(!same) break;
}

    int half = size / 2;

    if(same) return (first_color == 1) ? 1 : 0;
    else {
        divide++;
    return paper(a,b+half,half) + paper(a+half,b,half) + 
    paper(a,b,half) + paper(a+half,b+half,half);
    }  
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    blue = paper(0,0,n);
    total = 3 * (divide-1) + 4;
    white = total - blue;

    cout << white << "\n" << blue << "\n";

}