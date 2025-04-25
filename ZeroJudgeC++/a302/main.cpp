#include <bits/stdc++.h>

using namespace std;

const long long mod = 10007;

int main(){

    long long a, b, k, n, m;
    long long ap = 1, bp = 1, tol = 1, min = 1, div = 1;
    cin >> a >> b >> k >> n >> m;
    for(int i = 0; i < n; i ++) ap = ap * a % mod;
    for(int i = 0; i < m; i ++) bp = bp * b % mod;
    for(int i = m + 1; i <= k; i ++){
        tol = tol * i % mod;
    }

    for(int i = 1; i <= n; i ++){
        min = min * i % mod;
    }

    for(int i = 0; i < mod - 2; i ++){
        div = div * min % mod;
    }

    cout << ((ap * bp % mod) * tol % mod)* div % mod << endl;

    return 0;
}