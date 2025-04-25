#include <bits/stdc++.h>

using namespace std;

int solve(int n){
    cout << n << '\n';
    if(1000 <= n && n < 10000){
        return solve(solve(n / 100) * 100 + solve(n % 100));
    }else if (100 <= n && n < 1000){
        return solve(solve(n / 100) * solve(n / 10 % 10) * 100 + solve(n / 10 % 10) * solve(n % 10));
    }else if (10 <= n && n < 100){
        return solve((n / 10) * (n % 10));
    }else{
        return n;
    }
}

int main(){

    int n;
    cin >> n;
    cout << solve(n) << '\n';

    return 0;
}