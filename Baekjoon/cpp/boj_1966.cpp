//boj_1966 
#include <iostream>   // for std::cin, std::cout
#include <queue>      // for std::queue
#include <utility>    // for std::pair
#include <algorithm>  // for std::max_element
using namespace std;
int how_many;
int n,m;
int importance[101];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> how_many;

    while(how_many--){
        cin >> n >> m;
        queue<pair <int,int> > q;

        for(int i =0; i<n; i++){
            cin >> importance[i];
        }

        for(int i=0; i<n; i++){
            q.push(make_pair(i, importance[i]));
        }

        int cnt = 0;

       pair<int, int> want_find = make_pair(m, importance[m]);

        while(1){
            auto it = max_element(importance,importance+n);

            if(*it == q.front().second && q.front().first == want_find.first){
                cnt++;
                cout<< cnt << "\n";
                break;
            }
            else if(*it == q.front().second && q.front().first != want_find.first){
                cnt++;
                *it = 0;
                q.pop();
            }
            else if(*it != q.front().second){
                q.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}