#include <bits/stdc++.h> 

using namespace std;

const int MAX = 2e5 + 10;

vector<vector<int> > g(MAX);
vector<int> dis(MAX, -1);

void init(int n){
    for(int i = 0; i <= n; i ++){
        dis[i] = -1;
    }
}

int DFS(int ind){
    int mxin = ind;
    for(int i = 0; i < g[ind].size(); i++){
        if(dis[g[ind][i]] == -1){
            dis[g[ind][i]] = dis[ind] + 1;
            int k = DFS(g[ind][i]);
            if(dis[mxin] < dis[k]) mxin = k;
        }
    }
    return mxin;
}

int main(){

    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        g[a].push_back(b);
    }
    dis[1] = 0;
    int leaf = DFS(1);
    init(n);
    dis[leaf] = 0;
    cout << dis[DFS(leaf)] << '\n';

    return 0;
    
}