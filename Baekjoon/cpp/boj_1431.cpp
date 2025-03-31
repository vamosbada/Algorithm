//boj_1431
#include <bits/stdc++.h>
using namespace std;
int n;

bool cmp(string &a,string &b){

        int sum_a = 0;
        int sum_b = 0;
        for(auto c:a){
            if(isdigit(c)) sum_a += c - '0';
        }
         for(auto c:b){
            if(isdigit(c)) sum_b += c - '0';
        }

        if(a.size() != b.size()) return a.size() < b.size();
        else if(sum_a != sum_b) return sum_a < sum_b;
        else return a < b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr,arr+n,cmp);

    for(int i=0; i<n; i++){
        cout << arr[i] << '\n';
    }
}