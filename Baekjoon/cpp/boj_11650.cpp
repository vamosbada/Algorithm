//boj_11650번
#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[100000];
#define x first
#define y second

bool compare(pair<int,int>p,pair<int,int>q){
    if(p.x != q.x) return p.x < q.x;
    else return p.y < q.y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i].x >> a[i].y;
    }

    sort(a,a+n,compare);

    for(int i=0; i<n; i++){
        cout << a[i].x << " "<<a[i].y << "\n";
    }


}