#include <bits/stdc++.h> 
#define int long long

using namespace std;

map<int, int> mp; 


int DFS(int n){
    if (mp.find(n) != mp.end()) return mp[n];
    else{
        int ret = 100000000;
        if((n - 1) % 2 == 0) ret = min(ret, DFS((n - 1) / 2) + 1);
        else ret = min(ret, DFS(n / 2) + 1);
        ret = min(ret, DFS(n * 2) + 1);
        ret = min(ret, DFS(n * 2 + 1) + 1);
        return ret;
    }
}

signed main(){

    int a, b;
    cin >> a >> b;
    mp[a] = 0;
    cout << DFS(b) << '\n';

    return 0;
    
}