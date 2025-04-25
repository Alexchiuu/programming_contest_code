#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

using namespace std;


struct cost{


};

struct cmp{

    bool operator ()(const pair<cost,int> &a,const pair<cost,int> &b){
        return (a.first.len - a.first.mx + a.first.mx/2) > (b.first.len - b.first.mx + b.first.mx/2);
    }

};

signed main(){

    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int> > > g(n + 1);
    int a, b, c;
    for(int i = 0; i < m; i ++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
    }

    queue<pair<int,int> > dfs;
    cost unvis = {-1,0};
    vector<cost> dis(n + 1,unvis);

    while(!dfs.empty){
        
    }
    cout << dis[n].getcost() << '\n';

    return 0;    
}