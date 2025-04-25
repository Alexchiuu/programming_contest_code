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
    for(int i = 0; i < n; i++) cin >> g[i].x >> g[i].y;
    int sum = 0;
    int pol = 0;
    for(int i = 0; i < n - 1; i++){
        pol += __gcd(abs(g[i].x - g[i + 1].x),abs(g[i].y - g[i + 1].y));
        sum += g[i] ^ g[i + 1];
    }
    sum += g[n - 1] ^ g[0];
    pol += __gcd(abs(g[n - 1].x - g[0].x),abs(g[n - 1].y - g[0].y));
    cout << abs(sum) / 2 + 1 - pol / 2 << ' ' << pol << '\n';

    return 0;    
}