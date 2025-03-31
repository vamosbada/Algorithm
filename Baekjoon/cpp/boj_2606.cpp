//boj_2606
#include <bits/stdc++.h>
using namespace std;
int com_num,pair_num;
int cnt;
int arr[105][105];
bool is_virus[1000];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> com_num >> pair_num;


    if(com_num == 1){
        cout << 0;
        return 0;
    }  
    int k = pair_num;
    
    while(k--){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
        if(pair_num==1 && (a==1 || b==1)){
            cout << 1;
            return 0;
        }
    }

    queue <int> q;
    q.push(1);
    is_virus[1] = true;


    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=1; i<=com_num; i++){
            if((arr[curr][i] == 1) && !is_virus[i]){
                q.push(i);
                is_virus[i] = true;
                cnt++;
            }
       }
    }

    cout << cnt <<"\n";

}