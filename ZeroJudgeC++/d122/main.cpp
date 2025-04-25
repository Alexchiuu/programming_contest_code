#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a ;
    while(cin >> a){
        long long b=0 ;
        while(a>=1){
            a=a/5;
            b+=a;
        }
        cout << b << '\n';
    } 
    return 0;
}