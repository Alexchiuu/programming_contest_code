#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int w, h;
    cin >> w >> h;
    vector<string> g(h);
    for(int i = h - 1; i >= 0; i--) cin >> g[i];
    vector<int> dp(w);
    for(int i = 1; i <= w; i++) dp[i - 1] = i;
    for(int i = 0; i < h; i ++){
        for(int j = 1; j < w * 2; j += 2){
            if(g[i][j] == '-'){
                swap(dp[(j + 1) / 2],dp[(j - 1) / 2]);
                break;
            }
        }
    }
    for(auto &a: dp){
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}