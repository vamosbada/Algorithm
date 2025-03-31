//boj_11866
#include <bits/stdc++.h>
using namespace std;
int n,m;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    deque<int>dq;

    for(int i=1; i<=n; i++){
        dq.push_back(i);
    }

    auto cursor  = dq.begin();

    cout  << "<";
    while(!dq.empty()){
        for(int i=1; i<m; i++){
            cursor++;
            if(cursor == dq.end())
               cursor = dq.begin();
        }
        if(dq.size() != 1)
        cout << *cursor << ", ";
        else cout << *cursor;
        cursor = dq.erase(cursor);
        if(cursor == dq.end() && !dq.empty()) cursor = dq.begin();
    }
     cout << ">";
}
