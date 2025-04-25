#include <bits/stdc++.h>

using namespace std;

const int lg = 2e5 + 10;

vector<int> dsu(lg);

void init(){
    for(int i = 0; i < lg; i ++){
        dsu[i] = i;
    }
}

int query(int x){
    if(dsu[x] != x){
        dsu[x] = query(dsu[x]);
        return dsu[x];
    }
    return x;
}

void onion(int a, int b){
    dsu[query(a)] = query(b);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    init();


    vector<int> dp(n + 1,1);

    int mx = 0;
    int a, b;
    while(m --){
        cin >> a >> b;
        if(a > b) swap(a,b);
        if(query(a) != query(b)){
            dp[query(b)] += dp[query(a)];
            mx = max(mx,dp[query(b)]);
            onion(a,b);
            n--;
        }
        cout << n << ' ' << mx << '\n';
    }

    return 0;
}