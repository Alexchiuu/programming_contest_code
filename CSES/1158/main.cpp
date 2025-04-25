#include <bits/stdc++.h> 

using namespace std;

int main(){

    int n, x;
    cin >> n >> x;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    int dp[n+1][x+1];
    for(int i = 0; i <= x; i ++) dp[0][i] = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= x; j++){
            if(j + p[i] <= x){
                dp[i][j] = max(dp[i - 1][j + p[i]] + v[i], dp[i - 1][j]);
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    /*
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= x; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    cout << dp[n][0] << '\n';

    return 0;
    
}