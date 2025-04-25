#include <bits/stdc++.h>

using namespace std;

const int mod = 1e4 + 7;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;
    vector<int> arr(m);
    int sum;
    for(int i = 0; i < m; i ++){
        cin >> arr[i];
        sum += arr[i];
    }
    sum %= mod;
    if(sum % 2 == 1 || m == 1){
        cout << "NO\n";
        return 0;
    }
    vector<bool> dp(mod);
    vector<bool> dp2(mod);
    dp[0] = true;
    for(int i = 0; i < arr.size(); i ++){
        for(int j = 0; j < mod; j ++){
            if(dp[j]) dp2[(j + arr[i]) % mod] = true;
        }
        for(int j = 0; j < mod; j ++){
            dp[j] = dp[j] | dp2[j];
        }
    }
    if(dp[sum / 2]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}