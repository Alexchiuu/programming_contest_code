#include <bits/stdc++.h> 
#define ll long long

const int mod = 1e9 + 7;

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<ll> dp(x + 1);
    dp[0] = 1;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
        for(int j = arr[i]; j <= x; j ++){
            dp[j] += dp[j - arr[i]];
            dp[j] %= mod;
        }
    }
    cout << dp[x] << '\n';

    return 0;
    
}