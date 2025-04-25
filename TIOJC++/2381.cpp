#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<pair<int,int> > > g(n);
    vector<int> a(n);
    vector<int> x(n);
    vector<int> b(n);
    vector<int> y(n);
    vector<int> c(n);
    vector<int> d(n);
    vector<bool> v(n);
    vector<int> m(n,-1);

    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        pair<int,int> tmp;
        
        for(int j = 0; j < d; j ++){
            cin >> tmp.first >> tmp.second;
            g[tmp.first].push_back();
            g.push_back(tmp);
    }
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> x[i];
    for(int i = 0; i < n; i ++) cin >> b[i];
    for(int i = 0; i < n; i ++) cin >> y[i];
    for(int i = 0; i < n; i ++) cin >> c[i];

    queue<int> bfs;
    bfs.push(n - 1);
    while(!bfs.empty()){
        int tmp = bfs.front();
        tmp = 
    }


    return 0;
}