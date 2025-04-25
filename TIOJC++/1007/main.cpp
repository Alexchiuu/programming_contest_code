#include <bits/stdc++.h> 
#define int long long

using namespace std;

signed main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= m; i ++){
        for(int j = 0; j <= n; j ++) dp[i][0] += dp[i - 1][j];
        for(int j = 1; j <= n; j ++) dp[i][j] = dp[i - 1][j - 1];
    }
    int ans = 0;
    for(int i = 0; i <= n; i ++){
        ans += dp[m][i];
    }
    cout << ans << '\n';
    return 0;
    
}