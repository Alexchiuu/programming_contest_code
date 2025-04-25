#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> dp(80);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    for(int i = 4; i <= 76; i++){
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    int n;
    while(cin >> n){
        cout << dp[n] << '\n';
    }

    return 0;
}