//boj_11399
#include <bits/stdc++.h>
using namespace std;
int arr[1005];
int sum[1005];
int n;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    sort(arr,arr+n+1);

    sum[1] = arr[1];
    int total_sum = sum[1];
    for(int i=2; i<=n; i++){
        sum[i] = sum[i-1] + arr[i];
        total_sum += sum[i];
    }
    
    cout << total_sum << "\n";

}