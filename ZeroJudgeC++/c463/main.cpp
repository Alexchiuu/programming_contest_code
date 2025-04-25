#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 10;

vector<int> g[MAX];
vector<bool> vis(MAX);
vector<int> h(MAX);

void dep(int ind){
    int mx = -1;
    for(int i = 0; i < g[ind].size(); i ++){
        dep(g[ind][i]);
        mx = max(h[g[ind][i]],mx);
    }
    h[ind] = mx + 1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, p;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> k;
        for(int j = 0; j < k; j ++){
            cin >> p;
            g[i].push_back(p);
            vis[p] = true;
        }   
    }
    int root;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            root = i;
            break;
        }
    }
    dep(root);
    long long sum = 0;
    for(int i = 0; i <= n; i++){
        sum += h[i];
    }
    cout << root << '\n' << sum << '\n';

    return 0;
}