//boj_1912
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001]; //기본 값을 저장할 배열
int d[100001]; //연속합의 최댓값을 가지고 있을 배열


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n;

    
    //기본 값들을 저장할 배열을 받음
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    //d[1],d[2]를 구함
    d[1] = a[1];
    d[2] = max(a[2],a[1]+a[2]);


    //d의 나머지 부분을 구함
    for(int i=3; i<=n; i++){
        //이전의 합들 중 최댓값이 양수면 데려가고 아님 버림
        if(d[i-1] > 0) d[i] = d[i-1] + a[i];
        else d[i] = a[i];
    }
    

    // for(int i=1; i<=n; i++){
    //     cout << d[i] << " ";
    // }

    int p = *max_element(d+1,d+n+1);

    cout << p;
    
}