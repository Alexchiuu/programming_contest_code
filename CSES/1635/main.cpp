#include <bits/stdc++.h> 
#define ll long long

using namespace std;

const int mod = 1e9 + 7;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<ll> dp(x + 1);
    vector<int> arr(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        if(arr[i] <= x){
            dp[arr[i]] = 1;
        }
    }
    for(int i = 0; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - arr[j] > 0){
                dp[i] += dp[i - arr[j]];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[x] << '\n';

    return 0;
    
}