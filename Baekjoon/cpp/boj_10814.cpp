//백준 10814번
#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,string> info[100000];
pair<int,string> new_info[100000];
#define x first
#define y second

bool compare(pair<int,string> a,pair<int,string> b){
        return a.x < b.x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> info[i].x>> info[i].y;
    }

   copy(info,info+n,new_info);
   stable_sort(new_info,new_info+n,compare);


   for(int i=0; i<n; i++){
    cout << new_info[i].x <<" "<<new_info[i].y<<"\n";
    }
}