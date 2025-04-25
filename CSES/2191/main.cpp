#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

using namespace std;

struct pt{
    int x, y;
    int operator^ (pt vt){
        return x * vt.y - y * vt.x;
    }
};


signed main(){

    fastio

    int n;
    cin >> n;
    vector<pt> g(n);
    for(int i = 0; i < n; i ++) cin >> g[i].x >> g[i].y;
    int sum = 0;
    for(int i = 0; i < n - 1; i ++){
        sum += g[i] ^ g[i + 1];
    }
    sum += g[n - 1] ^ g[0];

    cout << abs(sum) << '\n';

    return 0;    
}