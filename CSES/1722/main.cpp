#include <bits/stdc++.h> 
#define ll long long

using namespace std;

const int mod = 1e9 + 7;

struct matrix{
    ll a, b, c, d;
    matrix operator* (matrix m){
        ll ra = a * m.a + b * m.c;
        ra %= mod;
        ll rb = a * m.b + b * m.d;
        rb %= mod;
        ll rc = c * m.a + d * m.c;
        rc %= mod;
        ll rd = c * m.b + d * m.d;
        rd %= mod;
        return {ra,rb,rc,rd};
    }
};

matrix pw(matrix k, ll n){
    if(n == 0){
        return {0,0,0,0};
    }
    if(n == 1){
        return k;
    }
    matrix x = pw(k, n / 2);
    if(n % 2 == 1){
        return x * x * k;
    }else{
        return x * x;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    cout << pw({1,1,1,0},n).b << '\n';

    return 0;
    
}