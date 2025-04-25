#include <bits/stdc++.h> 
#define int long long
using namespace std;

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    vector<vector<int> > dp(n + 1, vector<int> (m + 1, -1));
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) cin >> b[i];
    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    for(int i = 1; i <= m; i++) b[i] += b[i - 1];

    for(int i = 1; i <= n; i ++){
        if(a[i] >= 0){
            dp[i][0] = max(dp[i - 1][0],a[i]);
        }else break;
    }
    for(int i = 1; i <= m; i ++){
        if(b[i] >= 0){
            dp[0][i] = max(dp[0][i - 1],b[i]);
        }else break;
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(a[i] + b[j] < 0){
                dp[i][j] = -1;
                continue;
            }
            if(dp[i][j - 1] != -1 && dp[i - 1][j] != -1 && a[i] + b[j - 1] >= 0 && a[i - 1] + b[j] >= 0){
                dp[i][j] = min(max(a[i] + b[j],dp[i][j - 1]),max(a[i] + b[j],dp[i - 1][j]));
            }else if(dp[i][j - 1] != -1 && a[i] + b[j - 1] >= 0){
                dp[i][j] = max(a[i] + b[j], dp[i][j - 1]);
            }else if(dp[i - 1][j] != -1 && a[i - 1] + b[j] >= 0){
                dp[i][j] = max(a[i] + b[j], dp[i - 1][j]);
            }else{
                dp[i][j] = -1;
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
    
}