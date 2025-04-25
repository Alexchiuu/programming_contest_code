#include <bits/stdc++.h> 
#define ll long long
 
using namespace std;
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m, w, f;
    cin >> n >> m >> w >> f;
    int input;
    for(int i = 0; i < n; i++) cin >> input;
    for(int i = 0; i < n; i++) cin >> input;
    vector<vector<pair<int,int> > > g(n + 1);
    vector<ll> dis(n + 1,-1);
    int a, b, c;
    while(m --){
        cin >> a >> b >> c;
        g[a].push_back(make_pair(c,b));
        g[b].push_back(make_pair(c,a));
    }

    int s, e, G;
    cin >> s >> e >> b >> G;

    priority_queue<pair<ll,int> ,vector<pair<ll,int> >, greater<pair<ll,int> >> pq;
    pq.push({0,s});
    for(int i = 0; i < n; i ++){
        while(dis[pq.top().second] != -1) pq.pop();
        dis[pq.top().second] = pq.top().first;
        for(auto &x: g[pq.top().second]){
            pq.push({x.first + pq.top().first,x.second});
        }
        pq.pop();
    }
    
    if(b > dis[e]) cout << 0 << '\n';
    else cout << b - dis[e] << '\n';
    return 0;
    
}