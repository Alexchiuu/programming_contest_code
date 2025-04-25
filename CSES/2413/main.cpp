#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

using namespace std;

const int mod = 1e9 + 7;

signed main(){

    vector<vector<int> > dp(1e6+1, vector<int> (2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= 1e6; i ++){
        dp[i][0] = ((dp[i - 1][0] * 4) % mod + dp[i - 1][1]) % mod;
        dp[i][1] = (dp[i - 1][0] + (dp[i - 1][1] * 2) % mod) % mod;
    }

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << '\n';
    }

    return 0;    
}