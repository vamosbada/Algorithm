//boj_1620
#include <bits/stdc++.h>
using namespace std;
int n,m;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    unordered_map <string,int> key_to_value;
    unordered_map <int,string> value_to_key;

    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        key_to_value[s] = i;
        value_to_key[i] = s;
    }
    

    while(m--){
       string input;
       cin >> input;

        bool is_alpha = true;

       for(auto c : input){
        if(isalpha(c)) continue;
        else {
            is_alpha = false;
            break;
        }
       }

       if(is_alpha) {
        auto it = key_to_value.find(input);
        cout << it ->second << "\n";
       }
       else {
        int num = stoi(input);
       auto it = value_to_key.find(num);
       cout << it->second << "\n";
       }
    }

}