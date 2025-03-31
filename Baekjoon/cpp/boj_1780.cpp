//백준 1780번
#include <bits/stdc++.h>
using namespace std;
int n;
int minusone,zero,one;
int board[2200][2200];

void paper(int x,int y,int size){
 
int firstvalue = board[x][y];
bool isSame = true;

for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
        if(board[x + i][y + j] != firstvalue) {
            isSame = false;
            break;
        }
    }
      if(!isSame) break;
}

if(isSame){
    if(firstvalue == -1)
    minusone++;
    else if(firstvalue == 0)
    zero++;
    else if(firstvalue == 1)
    one++;
    return;
}

int newsize = size / 3;

for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        paper(x+i*newsize,y+j*newsize,newsize);
    }
}
}

int main(){

ios::sync_with_stdio(0);
cin.tie(0);

cin >> n;

for(int i=0; i<n; i++)
{
    for(int j=0; j<n; j++)
    cin >> board[i][j];
}

paper(0,0,n);

cout << minusone <<"\n" << zero<<"\n"<<one<<"\n";
}