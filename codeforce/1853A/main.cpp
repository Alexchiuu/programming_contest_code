#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

    int n;
    cin >> n;
    for(int k = 0; k < n; k ++){
        int m;
        cin >> m;
        int lst, nw;
        cin >> lst;
        int mn = 1e18;
        for(int i = 1; i < m; i++){
            cin >> nw;
            mn = min(nw - lst,mn);
            lst = nw;
        }
        if(mn < 0) cout << 0 << '\n';
        else cout << mn / 2 + 1 << '\n';
    }

    return 0;
}