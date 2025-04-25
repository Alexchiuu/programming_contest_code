#include <bits/stdc++.h> 

using namespace std;

const int mod = 1e9 + 7;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int> (n+1));
    vector<vector<int>> input(n + 1, vector<int> (n+1));
    dp[1][1] = 1;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '*'){
                input[i + 1][j + 1] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(input[i][j] == 1){
                dp[i][j] = 0;
                continue;           
            }else{
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= mod;
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][n] << '\n';

    return 0;
    
}