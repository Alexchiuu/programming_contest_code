#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int sum = 0;
    vector<vector<int>> dp(N + 2,vector<int>(N + 2));
    vector<vector<int>> dp2(N + 2,vector<int>(N + 2));
    for(int i = 1; i <= N; i++){
        cin >> dp[i][i];
        sum += dp[i][i];
    }
    for(int i = 1; i < N; i++){
        for(int j = 1; j + i <= N; j ++){
            dp[j][j + i] = max(dp2[j + 1][j + i] + dp[j][j],dp2[j][j + i - 1] + dp[j + i][j + i]);
            dp2[j][j + i] = min(dp[j + 1][j + i],dp[j][j  + i - 1]);
        }
    }
    cout << dp[1][N] << ' ' << sum - dp[1][N] << '\n'; 
    return 0;
    
}