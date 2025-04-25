#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MAX = 1e5;

int ans = 1e9;

vector<pii> g[MAX];
bool vis[MAX] = {};

void DFS(int ind){
    cout << "dfs" << ind << '\n';
    for(int i = 0; i < g[ind].size(); i ++){
        if(!vis[g[ind][i].first]){

            vis[g[ind][i].first] = true;
            DFS(g[ind][i].first);
            cout << vis[g[ind][i].first] << '\n';
        }
        for(int j = 0; j < i; j ++){
            int tem = -1;
            for(int k = 0; k < g[g[ind][i].first].size(); k ++){
                if(g[g[ind][i].first][k].first == g[ind][j].first){
                    tem = g[g[ind][i].first][k].second;
                    break;
                }
            }
            cout << "aaa" << '\n';
            if(tem == -1) ans = min(ans,g[ind][i].second + g[ind][j].second);
            else{
                ans = min(ans,max(min(g[ind][i].second + g[ind][j].second,tem),max(min(g[ind][i].second + tem,g[ind][j].second),min(g[ind][i].second,tem + g[ind][j].second))));
            }
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; i ++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    DFS(1);
    vis[1] = true;
    cout << ans << '\n';

    return 0;
}