//boj_11651번
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int n;
pair<int,int> a[100000];

bool compare(pair<int,int>p,pair<int,int>q){
    if(p.y == q.y){
        return p.x < q.x;
    }
    else return p.y < q.y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i].x >> a[i].y;
    }

    sort(a,a+n,compare);

    for(int i=0; i<n; i++){
        cout << a[i].x << " "<< a[i].y<< "\n";
    }
}