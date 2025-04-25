#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9;

int mx[4] = {0,0,1,-1};
int my[4] = {1,-1,0,0};

int main(){

    int q;
    cin >> q;
    int n, m;
    while(q --){
        cin >> n >> m;
        vector<vector<int> > g(n + 2,vector<int> (m + 2,MAX));
        vector<vector<int> > dis(n + 2,vector<int> (m + 2,MAX));
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                cin >> g[i][j];
            }
        }
        priority_queue<pair<int,pair<int,int> > > pq;
        pq.push({0,{1,1}});
        dis[0][0] = g[0][0];
        for(int j = 0; j < n * m; j ++){
            while(g[pq.top().second.first][pq.top().second.second] == -1){
                pq.pop();
            }
            auto & [d , k] = pq.top();
            auto & [x , y] = k;
            cout << "x: " << x << ",y: " << y << ",d: " << d << '\n';
            g[x][y] = -1;
            for(int i = 0; i < 4; i ++){
                cout << "aaa\n";
                cout << "g" << g[x + mx[i]][y + my[i]] << '\n';
                cout << "dis" << dis[x + mx[i]][y + my[i]] << '\n';
                cout << "eee\n";
                if(g[x + mx[i]][y + my[i]] != -1 && d + g[x + mx[i]][y + my[i]] < dis[x + mx[i]][y + my[i]]){
                    cout << "ccc\n";
                    dis[x + mx[i]][y + my[i]] = d + g[x + mx[i]][y + my[i]];
                    pq.push({dis[x + mx[i]][y + my[i]],{x + mx[i],y + my[i]}});
                }
                cout << "ddd\n";
            }
        }
        cout << dis[n][m] << '\n';
    }

    return 0;
}