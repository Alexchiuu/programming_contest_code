#include <bits/stdc++.h>

using namespace std;

const int mod = 1e5;

int mx[4] = {0,0,1,-1};
int my[4] = {1,-1,0,0};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while(cin >> n >> m){
        vector<vector<int> > g(n + 2,vector<int> (m + 2,1));
        vector<vector<int> > dp(n + 2,vector<int> (m + 2,0));
        vector<vector<int> > dv(n + 2,vector<int> (m + 2,0));
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                cin >> g[i][j];
            }
        }
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sx ++; sy ++; ex ++; ey ++;
        queue<pair<int,int>> bfs;
        bfs.push({sx,sy});
        dp[sx][sy] = 1;
        g[sx][sy] = 1;
        while(!bfs.empty()){
            
            pair<int,int> ind = bfs.front();
            //cout << "bfs " << ind.first << ' ' << ind.second << '\n';
            bfs.pop();
            dv[ind.first][ind.second] = 1;
            for(int i = 0; i < 4; i ++){
                if(dv[ind.first + mx[i]][ind.second + my[i]] != 1){
                    dp[ind.first + mx[i]][ind.second + my[i]] += dp[ind.first][ind.second];
                    dp[ind.first + mx[i]][ind.second + my[i]] %= mod;
                }
                if(g[ind.first + mx[i]][ind.second + my[i]] != 1){
                    bfs.push({ind.first + mx[i],ind.second + my[i]});
                    g[ind.first + mx[i]][ind.second + my[i]] = 1;
                }
            }
        }
        /*
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        */
        cout << dp[ex][ey] << '\n';
        
    }

    return 0;
}