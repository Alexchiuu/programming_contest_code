#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){

    fastio

    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(n + 1,vector<int> (n + 1));
    cin.ignore();
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            char input;
            cin.get(input);
            if(input == '*') dp[i][j] = 1;
        }
        cin.ignore();
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    int a, b, c, d;
    int x, y, z, w;
    for(int i = 0; i < m; i ++){
        cin >> a >> b >> c >> d;
        x = min(a,c);
        y = min(b,d);
        z = max(a,c);
        w = max(b,d);
        cout << dp[z][w] - dp[x - 1][w] - dp[z][y - 1] + dp[x - 1][y - 1] << '\n';
    }

    return 0;
}