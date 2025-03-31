//boj_2504
#include <bits/stdc++.h>
using namespace std;
string s;
int sum;
int num =1;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    stack <char> st;

    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(c == '(') {
            num *=2;
            st.push(c); 
        }
        else if(c == '['){
            num *=3;
            st.push(c);
        }
        else if(c == ')'){
            if(st.empty() || st.top() != '('){
                cout  << 0 << "\n";
                return 0;
            }
            else if(s[i-1] == '(') sum += num;
            st.pop();
            num /=2;
        }
        else if( c == ']'){
            if(st.empty() || st.top() != '['){
                cout  << 0 << "\n";
                return 0;
            }
            else if(s[i-1] == '[') sum += num;
            st.pop();
            num /=3;
        }

    }

    if(st.empty()) cout << sum;
    else cout << 0;

}