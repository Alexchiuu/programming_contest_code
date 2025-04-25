#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1,vector<int> (b.size() + 1));

    for(int i = 0; i <= a.size(); i ++) dp[i][0] = i;
    for(int i = 0; i <= b.size(); i ++) dp[0][i] = i;

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            int k = 1;
            if(a[i - 1] == b[j - 1]) k = 0;
            dp[i][j] = min(min(dp[i - 1][j - 1] + k , dp[i - 1][j] + 1), dp[i][j - 1] + 1);
        }
    }
    cout << dp[a.size()][b.size()] << '\n';

    return 0;
    
}