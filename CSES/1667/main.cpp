#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n + 1);
    vector<int> par(n + 1,-1);

    int a, b;
    while(m --){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> bfs;
    bfs.push(1);
    par[1] = 0;
    while(!bfs.empty()){
        int ind = bfs.front();
        bfs.pop();
        for(auto &a: g[ind]){
            if(par[a] == -1){
                bfs.push(a);
                par[a] = ind;
            }
        }
    }

    if(par[n] == -1){
        cout << "IMPOSSIBLE\n";
    }else{
        vector<int> ans;
        while(n != 1){
            ans.push_back(n);
            n = par[n];
        }
        ans.push_back(1);
        cout << ans.size() << '\n';
        for(int i = ans.size() - 1; i >= 0; i --){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
    
}