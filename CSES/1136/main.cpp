#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    swap(n, m);
    vector<int> g(n + 1);
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a] ++;
        g[b] ++;
    }
    for(int i = 1; i <= n; i++){
        g[i] = (g[i] * g[i] - 1) / 2;
    }
    for(int i = 1; i <= n; i++){
        cout << g[i] << ' ';
    }
    cout << '\n';

    return 0;    
}