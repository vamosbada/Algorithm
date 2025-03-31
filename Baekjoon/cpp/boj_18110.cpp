//boj_18110
#include <iostream>  // std::cout, std::cin
#include <algorithm> // std::sort
#include <numeric>   // std::accumulate
using namespace std;
int arr[300003];
int n;
int cut_line;
int sum;
int result;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    cut_line = int(n * 0.15 + 0.5);
    

    if( n <= 2 * cut_line){
        cout <<  0;
        return 0;
    }

    sum = accumulate(arr+cut_line,arr+n-cut_line,0);

    result = int((sum / (double)(n - cut_line * 2)) + 0.5);

    cout << result;

    return 0;
}
