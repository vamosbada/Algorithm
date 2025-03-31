//boj_11286
#include <bits/stdc++.h>
using namespace std;
int n;

class cmp{
    public:
    bool operator()(int a,int b){
        if(fabs(a) != fabs(b)) {
            return fabs(a) > fabs(b);
        }
        else return a > 0 &&  b < 0;
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    priority_queue<int,vector<int>,cmp> pq;
    
    while(n--){
        int x;
        cin >> x;
        if(x==0 && pq.empty()) {
            cout << 0 << "\n";
        }
        else if(x==0 && !pq.empty()){
            cout << pq.top() << "\n";
            pq.pop();
        }
        else {
            pq.push(x);
        }
    }

}