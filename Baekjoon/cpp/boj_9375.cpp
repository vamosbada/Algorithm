//boj_9375
#include <bits/stdc++.h>
using namespace std;
int n;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;



    while(n--){
        int how_many = 0;
        string a,b;
        int result = 0;
        int mul=1;

        unordered_map <string,int> mp;

        cin >> how_many;

        if(how_many == 0) {
            cout << 0 << "\n";
            continue;
        }
        for(int i=0; i<how_many; i++){
            cin >> a >> b;
            mp[b]++;
        }
        for(auto c : mp){
            if(c.second == how_many) {
                mul = 0;
                break;
            }
            if(how_many == mp.size()){
                mul = 0;
                break;
            }
            mul *= c.second;
        }
        result = how_many + mul;
        cout << result << "\n";
    }
}    
 