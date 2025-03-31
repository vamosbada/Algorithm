//boj_11723
#include <bits/stdc++.h>
using namespace std;
int t;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    string s;
    int x;
    int bit = 0;


    while(t--){
        cin >> s;

        if(s == "add"){
            cin >> x;
            bit |= 1<<(x-1);
        }
        else if( s == "remove"){
            cin >> x;
            bit &= ~(1<<(x-1));
        }
        else if (s == "check") {
            cin >> x;
            cout <<((bit & (1<<(x-1))) ? 1 : 0) << "\n";
        }
        else if (s == "toggle"){
            cin >> x;
            bit ^= (1<<(x-1));
        }
        else if (s == "all") 
            bit = (1 << 20) -1;
        else if (s == "empty") bit = 0;
    }

    return 0;
}
