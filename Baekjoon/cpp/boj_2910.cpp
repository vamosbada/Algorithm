//백준 2910번
#include <bits/stdc++.h>
using namespace std;
int n,c;
int a[1001];
unordered_map<int,int> freq;
unordered_map<int,int> order;

bool cmp(int x, int y){
    if(freq[x] == freq[y]){
        return order[x] < order[y]; 
    }
    return freq[x] > freq[y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for(int i=0; i<n; i++){
        cin >> a[i];
        freq[a[i]]++;
        if(order.find(a[i]) == order.end()){
            order[a[i]] = i;
        }
    }

    stable_sort(a,a+n,cmp);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }

    return 0;
}