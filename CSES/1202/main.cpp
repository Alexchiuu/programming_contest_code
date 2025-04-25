#include <bits/stdc++.h> 
#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int L = 1e9 + 7;

const int MAX = 1e5 + 10;

vector<pair<int,int> > g[MAX];
vector<vector<int> > dp(MAX,{L,0,L,0});
vector<int> inn(MAX);


signed main(){

    fastio

    int n, m;
    cin >> n >> m;
    int  a, b, c;

    for(int i = 0; i < m; i ++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        inn[b] ++;
    }

    queue<int> q;
    for(int i = 2; i <= n; i ++){
        if(inn[i] == 0){
            q.push(i);
            cout << "ll" << i << ' ';
        }
    }

    while(q.size() > 0){
        int tmp = q.front();
        cout << tmp << '\n';
        for(int i = 0; i < g[tmp].size(); i ++){
            inn[g[tmp][i].first] --;
            if(inn[g[tmp][i].first] == 0 && g[tmp][i].first != 1){
                q.push(g[tmp][i].first);
            }
        }
    }

    q.push(1);
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;
    while(q.size() > 0){
        int tmp = q.front();
        cout << tmp << '\n';
        q.pop();
        for(int i = 0; i < g[tmp].size(); i ++){
            dp[g[tmp][i].first][0] = min(dp[tmp][0] + g[tmp][i].second, dp[g[tmp][i].first][0]);
            if(dp[g[tmp][i].first][0] == dp[tmp][0] + g[tmp][i].second) dp[g[tmp][i].first][1] = (dp[tmp][1] + dp[g[tmp][i].first][1]) % L;
            dp[g[tmp][i].first][2] = min(dp[tmp][2] + 1, dp[g[tmp][i].first][2]);
            dp[g[tmp][i].first][3] = max(dp[tmp][3] + 1, dp[g[tmp][i].first][3]);
            inn[g[tmp][i].first] --;
            cout << "inn" << g[tmp][i].first << ":" << inn[g[tmp][i].first] << '\n';
            if(inn[g[tmp][i].first] == 0){
                q.push(g[tmp][i].first);
            }
        }
    }   cout << dp[n][0] << ' ' << dp[n][1] << ' ' << dp[n][2] << ' ' << dp[n][3] << '\n';
    return 0;    
}