#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<vector<int> > g(n + 1, vector<int> (n + 1));
    vector<bool> vis0(n + 1, 0);
    vector<bool> vis1(n + 1, 0); 

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> g[i][j];
        }
    }

    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> >> ,greater<pair<int, pair<int,int>>>> q;

    q.push({0,{1,0}});

    while(!q.empty()){
        pair<int,pair<int,int> > tmp = q.top();
        q.pop();

        if(tmp.second.second == 0){
            if(vis0[tmp.second.first]){
                continue;
            }else vis0[tmp.second.first] = true;
        }else{
            if(vis1[tmp.second.first]){
                continue;
            }else vis1[tmp.second.first] = true;
        }

        if(tmp.second.first == n){
            cout << tmp.first << '\n';
            break;
        }

        if(tmp.second.second == 0){
            for(int i = 1; i <= n; i ++){
                if(tmp.second.first != i){
                    //cout << tmp.first + g[tmp.second.first][i] * a << " " << i << " " << 0 << '\n';
                    q.push({tmp.first + g[tmp.second.first][i] * a,{i, 0}});
                }
            }
        }

        for(int i = 1; i <= n; i ++){
            if(tmp.second.first != i){
                q.push({tmp.first + g[tmp.second.first][i] * b + c,{i, 1}});
            }
        }
    }


    return 0;
}