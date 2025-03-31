//boj_11659
#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[100005];
int a,b;
int part_sum;
int prefix_sum[100005];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    for(int i=1; i<=n; i++){
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
    
    while(m--){
        cin >> a >> b;
        part_sum = prefix_sum[b] - prefix_sum[a-1];
        cout << part_sum << "\n";
    }

}