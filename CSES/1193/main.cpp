#include <bits/stdc++.h> 

using namespace std;

const char mov[4] = {'U','D','L','R'};
const int mx[4] = {-1,1,0,0};
const int my[4] = {0,0,-1,1};

int main(){

    int n, m;
    cin >> n >> m;
    cin.ignore();
    int stx, sty, ex, ey;
    vector<vector<char> > g(n + 2,vector<char> (m + 2,'#'));
    vector<vector<int> > par(n + 2,vector<int> (m + 2));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin.get(g[i][j]);
            if('A' == g[i][j]){
                stx = i;
                sty = j;
            }
            if('B' == g[i][j]){
                ex = i;
                ey = j;
            }
        }
        cin.ignore();
    }
    
    bool check = false;
    queue<pair<int,int> > bfs;
    bfs.push({stx,sty});
    while(!bfs.empty() && !check){
        auto & [x, y] = bfs.front();
        bfs.pop();
        for(int i = 0; i < 4; i ++){
            if(g[x + mx[i]][y + my[i]] != '#'){
                par[x + mx[i]][y + my[i]] = i;
                bfs.push({x + mx[i],y + my[i]});
                g[x + mx[i]][y + my[i]] = '#';
                if(x + mx[i] == ex && y + my[i] == ey){
                    check = true;
                    break;
                }
            }
        }
    }
    if(check){
        cout << "YES\n";
        vector<char> ans;
        while(ex != stx || ey != sty){
            ans.push_back(mov[par[ex][ey]]);
            int k = par[ex][ey];
            ex -= mx[k];
            ey -= my[k];
        }
        cout << ans.size() << '\n';
        for(int i = ans.size() - 1; i >= 0; i --){
            cout << ans[i];
        }
        cout << '\n';

    }else{
        cout << "NO\n";
    }


    return 0;
    
}