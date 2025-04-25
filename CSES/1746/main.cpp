#include <bits/stdc++.h> 

using namespace std;

const int mod = 1e9 + 7;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 2);
    vector<vector<int> > dp(n + 1,vector<int> (m + 2,0));
    for(int i = 1; i <= n; i++) cin >> arr[i];
    if(arr[1] == 0){
        for(int i = 1; i <= m; i++) dp[1][i] = 1;
    }else{
        dp[1][arr[1]] = 1;
    }
    for(int i = 2; i <= n; i++){
        if(arr[i] == 0){
            for(int j = 1; j <= m; j ++){
                dp[i][j] = dp[i - 1][j];
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] = dp[i][j] % mod;
                dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] = dp[i][j] % mod;
            }
        }else{
            dp[i][arr[i]] = dp[i - 1][arr[i]];
            if(arr[i] - 1 > 0){
                dp[i][arr[i]] += dp[i - 1][arr[i] - 1];
                dp[i][arr[i]] = dp[i][arr[i]] % mod;
            }
            if(arr[i] + 1 <= m){
                dp[i][arr[i]] += dp[i - 1][arr[i] + 1];
                dp[i][arr[i]] = dp[i][arr[i]] % mod;
            }
        }
    }

    /*
    for(auto &a: dp){
        for(auto &b: a){
            cout << b << ' ';
        }
        cout << '\n';
    }
    */

    if(arr[n] == 0){

        int cnt = 0;
        for(int i = 1; i <= m; i ++){
            cnt += dp[n][i];
            cnt = cnt % mod;
        }
        cout << cnt << '\n';
    }else{
        cout << dp[n][arr[n]] << '\n';
    }

    return 0;
    
}