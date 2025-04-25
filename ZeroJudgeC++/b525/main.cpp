#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e8 + 7;

struct matrix{
    int a, b, c, d;
    matrix operator* (matrix x){
        return {(a * x.a % mod + b * x.c % mod) % mod,
                (a * x.b % mod + b * x.d % mod) % mod, 
                (c * x.a % mod + d * x.c % mod) % mod, 
                (c * x.b % mod + d * x.d % mod) % mod};
    }
};

matrix pow(matrix x,int n){
    if(n == 0) return {1,1,0,0};
    if(n == 1) return x;
    matrix k = pow(x,n / 2);
    if(n % 2 == 1) return k * k * x;
    else return k * k;
}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, f, k;
    while(cin >> m >> f >> k){
        matrix c = pow({0,1,1,1},k);
        cout << ((c.a * m % mod + c.b * f % mod) % mod + (c.c * m % mod + c.d * f % mod) % mod) % mod << '\n';
    }

    return 0;
}