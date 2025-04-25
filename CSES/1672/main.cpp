#include <bits/stdc++.h> 
#define ll long long


using namespace std;

const ll INF = 1e18;

ll mn(ll a, int b){
    if(a < b) return a;
    else return b;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll> > d(n + 1,vector<ll> (n + 1,INF));
    int a, b, c;
    for(int i = 0; i < m; i ++){
        cin >> a >> b >> c;
        d[a][b] = mn(d[a][b],c);
        d[b][a] = mn(d[b][a],c);
    }
    for(int i = 1; i <= n; i ++) d[i][i] = 0;
    for(int k = 1; k <= n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }

    while(q --){
        cin >> a >> b;
        if(d[a][b] > 1e13) cout << -1 << '\n';
        else cout << d[a][b] << '\n';
    }

    return 0;
    
}