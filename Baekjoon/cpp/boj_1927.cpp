#include <bits/stdc++.h>
using namespace std;
int n;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    priority_queue <int,vector<int>,greater<int> > pq;

    while(n--){
        int x;
        cin >> x;
        if(x==0 && pq.empty()) cout << 0 << "\n";
        else if(x==0 && !pq.empty()) {
            cout << pq.top() << "\n";
            pq.pop();
        }
        else pq.push(x);
    }

    
}