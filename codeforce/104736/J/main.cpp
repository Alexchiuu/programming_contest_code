#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 10;

vector<int> g[MAX];
int ans[MAX] = {};
bool vis[MAX] = {};

void DFS(int ind, int fr, int x){
    if(x >= ind) ans[ind] = x;
    for(int i = 0; i < g[ind].size(); i ++){
        if(!vis[g[ind][i]] && g[ind][i] != fr){
            DFS(g[ind][i], ind, x);
        }
    }
}

int main(){

    int n;
    cin >> n;
    int a, b;
    for(int i = 1; i < n; i ++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = n; i > 0; i --){
        DFS(i,0,i);
        vis[i] = true;
    }
    for(int i = 1; i <= n; i ++){
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}