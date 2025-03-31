//boj_1764
#include <bits/stdc++.h>
using namespace std;
int n,m;

int main(){

    cin >> n >> m;
    set <string> no_listen;
    set <string> no_see;
    vector <string> no_see_no_listen (100000);

    string s;

    while(n--){
       cin >> s;
       no_listen.insert(s);
    }
    while(m--){
        cin >> s;
        no_see.insert(s);
    }

    auto it = set_intersection(no_listen.begin(),no_listen.end(),no_see.begin(),no_see.end(),no_see_no_listen.begin());

    no_see_no_listen.resize(it - no_see_no_listen.begin());

    cout << no_see_no_listen.size() << "\n";

    sort(no_see_no_listen.begin(),no_see_no_listen.end());

    for(string st : no_see_no_listen){
        cout << st << "\n";
    }


}