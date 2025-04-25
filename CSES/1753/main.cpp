#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

using namespace std;

const int mod = 1e9 + 7;
const int p = 127;
const int MAX = 1e6 + 10;

signed main(){

    fastio

    string s;
    vector<int> hst(MAX);
    cin >> s;
    int prime = 1;
    for(int i = 0; i < s.size(); i ++){
        hst[i + 1] = (s[i] - 'a' + 1) * prime % mod;
        prime = prime * p % mod;
    }
    for(int i = 1; i <= s.size(); i ++) hst[i] = (hst[i - 1] + hst[i]) % mod;
    string t;
    cin >> t;
    int hsh = 0;
    prime = 1;
    for(int i = 0; i < t.size(); i ++){
        hsh = (hsh + (t[i] - 'a' + 1) * prime % mod) % mod;
        prime = prime * p % mod;
    }
    prime = 1;
    int ans = 0;
    for(int i = t.size(); i <= s.size(); i ++){
        if((hst[i] - hst[i - t.size()] + mod) % mod == (hsh * prime) % mod) ans ++;
        prime = prime * p % mod;
    }
    cout << ans << '\n';

    return 0;    
}