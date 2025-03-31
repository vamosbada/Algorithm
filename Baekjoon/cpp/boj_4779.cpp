//백준 4779번
#include <bits/stdc++.h>
using namespace std;
int a[531442];

void cantor(int p,int q)
{
    int length = q-p+1;
    if(length <= 1)
    return;

    int onethird = p+length / 3;
    int twothird = p+(2*length / 3);

    fill(a+onethird,a+twothird,0);
    cantor(p,onethird-1);
    cantor(twothird,q);
}

int main(){

ios::sync_with_stdio(0);
cin.tie(0);

int n;

while(cin >>n){

int len = (int)pow(3,n);

for(int i=0; i<len; i++){
    a[i] = 1;
}

cantor(0,len-1);

for(int i=0; i<len; i++){
    if(a[i] == 1)
    cout << '-';
    else cout<<' ';
}
cout << "\n";
}
}