#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    while(m --){
        int S = 0;
        vector<int> arr(n);
        for(int i = 0; i < n; i ++){
            cin >> arr[i];
            S += arr[i];
        }
        if(S % 2 == 1){
            cout << "No\n";
            continue;
        }else S /= 2;
        vector<bool> dp(S + 1);
        dp[0] = true;
        for(int i = 0; i < arr.size(); i ++){
            for(int j = S - arr[i]; j >= 0; j --){
                if(dp[j]) dp[j + arr[i]] = true;
            }
        }
        if(dp[S]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
    
}