//백준 5430번
#include <bits/stdc++.h>
using namespace std;
int t,n;
string query,s;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    //테스트 횟수를 입력받음
    cin >> t;
    
    while(t--){
        cin >> query >> n >> s;
        deque<int> dq;
        bool isReversed = false;

        //문자열 파싱
        string num ="";
        for (auto c : s){
            if(isdigit(c)){
                num += c;
            }else if(!num.empty()){
                dq.push_back(stoi(num));
                num = "";
            }
        }

        string result = "";
        //쿼리 처리
        for(auto c:query){
            if(c=='R'){
                isReversed = !isReversed;
                continue;
            }
            if(dq.empty()){
                result = "error";
                break;
            }
            if(isReversed == true) {
                dq.pop_back();
            } else dq.pop_front();
        }

        //결과값 출력
        if(result == "error"){
            cout << result << "\n";
            continue;
        }
        if(isReversed){
            reverse(dq.begin(),dq.end());
        }
        cout << "[";
        for(int i=0; i<dq.size();i++){
            cout << dq[i];
            if(i!=dq.size()-1) cout << ",";
        }
        cout << "]\n";

    }

  
}