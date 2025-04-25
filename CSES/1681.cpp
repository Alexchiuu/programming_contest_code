#include <bits/stdc++.h> 
#define int long long

using namespace std;

const int mod = 1e9 + 7;
const int mx = 1e5 + 10;

vector<int> g[mx];
vector<int> in(mx);
vector<int> dp(mx);

signed main(){

    int n, m;
    cin >> n >> m;

    int a, b;
    while(m --){
        cin >> a >> b;
        g[a].push_back(b);
        in[b] ++;
    }

    dp[1] = 1;

    queue<int> topo;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            topo.push(i);
        }
    }

    while(!topo.empty()){
        int ind = topo.front();
        topo.pop();

        for(auto &a: g[ind]){
            dp[a] += dp[ind];
            dp[a] %= mod;
            in[a] --;
            if(in[a] == 0){
                topo.push(a);
            }
        }
    }


    cout << dp[n] << '\n';

    return 0;
    
}