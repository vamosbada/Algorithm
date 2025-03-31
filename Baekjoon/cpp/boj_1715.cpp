//boj_1755
#include <bits/stdc++.h>
using namespace std;
int n;
int sum;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    priority_queue <int,vector<int>,greater<int> > pq;
    
    while(n--){
        int x;
        cin >> x;
        pq.push(x);
    }

    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sum += a+b;
        pq.push(a+b);
    }


    cout << sum;
}