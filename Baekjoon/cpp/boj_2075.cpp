//boj_2075
#include <bits/stdc++.h>
using namespace std;
int n;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    priority_queue <int,vector<int>,greater<int> > pq;
    
    for(int i=0; i<n*n; i++){
        int x;
        cin >> x;
        pq.push(x);
        if(pq.size() > n){
            pq.pop();
        }
    }

    cout << pq.top();
    
}