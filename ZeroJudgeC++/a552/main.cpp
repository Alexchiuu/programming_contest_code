#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while(cin >> n >> m){
        vector<int> ans;
        vector<int> arrin(n);
        vector<vector<int> > g(n);
        vector<bool> vis(n);
        priority_queue<int,vector<int>, greater<int> > pq;
        int a, b;
        for(int i = 0; i < m; i ++){
            cin >> a >> b;
            arrin[b] ++;
            g[a].push_back(b);
        }
        for(int i = 0; i < n; i ++){
            if(arrin[i] == 0){
                pq.push(i);
                vis[i] = true;
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            int ind = pq.top();
            pq.pop();
            for(int i = 0; i < g[ind].size(); i ++){
                if(!vis[g[ind][i]] && --arrin[g[ind][i]] == 0){
                    vis[g[ind][i]] = true;
                    pq.push(g[ind][i]);
                }
            }
        }
        for(auto &a: ans){
            cout << a << ' ';
        }
        cout << '\n';
    }
    return 0;
}