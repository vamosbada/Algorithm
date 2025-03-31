//백준 11656번
#include <bits/stdc++.h>
using namespace std;
string s;
string a[1001];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for(int i=0; i<s.length(); i++){
        string new_s = s;
        new_s.erase(new_s.begin(),new_s.begin()+i);
        a[i] = new_s;
    }
    sort(a,a+s.length());

    for(int i=0; i<s.length(); i++){
        cout << a[i] << "\n";
    }
}