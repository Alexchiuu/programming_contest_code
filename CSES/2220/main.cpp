#include <bits/stdc++.h> 
#define ll long long

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];
    ll dp[n][n] = {};
    ll dp2[n][n] = {};
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[i][i] = arr[i];
        //dp2[i][i] = arr[i];
    }
    for(int i = 1; i < n; i++){
        int l = 0, r = i;
        for(r, l; r < n; r ++, l ++){
            dp[l][r] = max(dp2[l + 1][r] + arr[l], dp2[l][r - 1] + arr[r]);
            //cout << "dp[" << l << "][" << r <<"]:" << dp[l][r] << '\n';
            dp2[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
            //cout << "dp2[" << l << "][" << r <<"]:" << dp[l][r] << '\n';
        }
    }
    cout << dp[0][n - 1] << '\n';

    return 0;
    
}