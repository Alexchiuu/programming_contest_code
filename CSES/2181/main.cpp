#include <bits/stdc++.h> 

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<vector<int> > > dp(n + 1,vector<vector<int> > (m + 1, vector<int> (3,0)));
    for(int i = 0; i <= n; i ++) dp[i][0][1] = 1;
    for(int i = 0; i <= m; i ++) dp[0][i][1] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            dp[i][j][0] = (dp[i - 1][j][1] + dp[i - 1][j][2]) * (dp[i][j - 1][1] + dp[i][j - 1][2]);
            dp[i][j][1] = (dp[i][j - 1][1] + dp[i][j - 1][2]) * dp[i - 1][j][0];
            dp[i][j][2] = (dp[i - 1][j][1] + dp[i - 1][j][2]) * dp[i][j - 1][0];
        }
    }
    cout << dp[n][m][1] + dp[n][m][2] << '\n';
    return 0;
    
}