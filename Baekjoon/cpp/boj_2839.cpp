//백준 2839번
#include <bits/stdc++.h>
using namespace std;
int quotient;
int cnt;
int kg;
int three_kg;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> kg;

    quotient = kg / 5;
    int k = 0;
    k = kg % 5;
    if(k==0){
        cout << quotient <<"\n";
        return 0;
    }

    int remainder = 0;

    while(1){
        if(quotient == 0){
            three_kg = kg / 3;
            remainder = kg % 3;
            if(remainder == 0){
            cout << three_kg<<"\n";
            return 0;
            }
            else {
                cout << -1 << "\n";
                return 0;
            }
        }

        three_kg =  k / 3;
        remainder = k % 3;
        if(remainder % 3 == 0 && three_kg > 0){
            cnt = three_kg + quotient;
            cout << cnt << "\n";
            return 0 ;
        }
        else{
             k += 5;
             quotient--;
        }
    }
}