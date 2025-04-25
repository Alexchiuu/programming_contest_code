#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

using namespace std;

const int MAX = 2e5 + 10;

vector<vector<int> > g(MAX, vector<int>());
vector<int> ems(MAX,0);

void dfs(int ind){
    for(int i = 0; i < g[ind].size(); i ++){
        dfs(g[ind][i]);
        ems[ind] += ems[g[ind][i]] + 1;
    }
}

signed main(){

    fastio;
    int n;
    cin >> n;
    int input;
    for(int i = 2; i <= n; i ++ ){
        cin >> input;
        g[input].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << ems[i] << ' ';
    }
    cout << '\n';
    return 0;    
}