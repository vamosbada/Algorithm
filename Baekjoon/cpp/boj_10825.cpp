//백준 10825번
#include <bits/stdc++.h>
using namespace std;
int t;
unordered_map <string,int> korean;
unordered_map <string,int> english;
unordered_map <string,int> math;

bool cmp(string a, string b){
    if(korean[a] != korean[b]){
        //cout << a << korean[a] << b <<  korean[b] << "\n";
        return korean[a] > korean[b];
    }
    if(english[a] != english[b]){
        return english[a] < english[b];
    }
    if(math[a] != math[b]){
        return math[a] > math[b];
    }

    return a < b;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

     vector<string> v;

    while(t--){
        string name;
        int k,e,m;
        cin >> name >> k >> e >> m;
        v.push_back(name);
        korean[name] = k;
        english[name] = e;
        math[name] = m;
    }

    sort(v.begin(),v.end(),cmp);

    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
}