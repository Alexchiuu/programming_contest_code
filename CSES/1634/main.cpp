#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1,1000001);
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    //sort(arr.begin(), arr.end(),greater<int>());
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int input = arr[i];
        for(int j = input; j <= x;j ++){
            dp[j] = min(dp[j - input] + 1,dp[j]);
        }
    }
    if(dp[x] == 1000001) cout << -1 << '\n';
    else cout << dp[x] << '\n';

    return 0;
    
}