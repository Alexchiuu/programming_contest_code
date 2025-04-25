#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b;
    while(cin >> a >> b && !(a == 0 && b == 0)){
        if(b < a) swap(a,b);
        int carry = 0;
        int sum = 0;
        while(a != 0){
            if(a % 10 + b % 10 + carry >= 10){
                carry = 1;
                sum ++;
            }else carry = 0;
            a /= 10,b /= 10;
        }
        if(sum == 0) cout << "No carry operation." << '\n';
        else if(sum == 1) cout << "1 carry operation." << '\n';
        else cout << sum << " carry operations." << '\n';
    }

    return 0;
}