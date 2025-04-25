#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int pow(int x, int k){
    if(k == 1) return x;
    int tmp = pow(x, k/2);
    if(k % 2 == 1) return (tmp * tmp) % mod * x % mod;
    else return tmp * tmp % mod;
}

signed main(){

    fastio

    int n;
    cin >> n;

    int number = 1;
    int sum = 1;
    int product = 1;
    
    for(int i = 0; i < n; i++){
        int x, k;
        cin >> x >> k;
        number *= (k + 1);
        number %= mod;
        sum *= (pow(x,k + 1) - 1);
        sum /= (x - 1);
        sum %= mod;
        product *= pow(x,k);
        product %= mod;
    }
    if(number % 2 == 1){
        product = pow(product,number / 2) * sqrt(product);
        product %= mod;
    }else product = pow(product,number / 2);

    cout << number << ' ' << sum << ' ' << product << '\n';

    return 0;    
}