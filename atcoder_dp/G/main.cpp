#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main(){

    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> dp(n + 1);

    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] += dp[i - 1] * 2 % mod;
        for(int k = 1; k < i; k ++){
            dp[i] += ((dp[k] * dp[i - 1 - k]) % mod);
            dp[i] %= mod;
        }
        //cout << dp[i] << '\n';
    }
    cout << dp[n] << '\n';
    

    return 0;

}