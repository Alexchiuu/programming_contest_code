#include <bits/stdc++.h> 
#define ll long long

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int> > > g(n + 1);
    vector<ll> dis(n + 1,-1);
    int a, b, c;
    while(m --){
        cin >> a >> b >> c;
        g[a].push_back(make_pair(c,b));
    }
    priority_queue<pair<ll,int> ,vector<pair<ll,int> >, greater<pair<ll,int> >> pq;
    pq.push({0,1});
    for(int i = 0; i < n; i ++){
        while(dis[pq.top().second] != -1) pq.pop();
        dis[pq.top().second] = pq.top().first;
        for(auto &x: g[pq.top().second]){
            pq.push({x.first + pq.top().first,x.second});
        }
        pq.pop();
    }
    
    for(int i = 1; i <= n; i ++){
        cout << dis[i] << ' ';
    }
    cout << '\n';

    return 0;
    
}