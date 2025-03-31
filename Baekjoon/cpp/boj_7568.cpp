//백준 7568번
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
pair<int,int> infor[51];
int ranks[51];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin >> infor[i].x >> infor[i].y;
    }
   
    for(int i=0; i<n; i++)
    {
        int rank = 1;
        for(int j=0; j<n; j++)
        {
            if(i !=j && infor[i].x < infor[j].x && infor[i].y<infor[j].y)
            rank++;
        }
        ranks[i] = rank;
    }


    for(int i=0; i<n; i++)
    {
        cout << ranks[i]<<"\n";
    }

}