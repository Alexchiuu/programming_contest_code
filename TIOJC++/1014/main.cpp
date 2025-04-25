#include <bits/stdc++.h> 

using namespace std;

int arr[20];

int main(){

    int n;
    cin >> n;
    int n2 = pow(2,n);
    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
    }

    vector<vector<int> > dp(110000, vector<int> (n + 1, -1));

    for(int i = 0; i <= n; i ++) dp[0][i] = i;

    for(int i = 1; i < n2; i ++){
        for(int j = 1; j <= n; j ++){
            int j2 = pow(2,j - 1);
            if(i ^ j2 < i){
                int mn = 1e9;
                for(int k = 0; k <= n; k ++){
                    //cout << i << ' ' << j << ' ' << k << '\n';
                    if(dp[i ^ j2][k] == -1) continue;
                    if((dp[i ^ j2][k] + abs(j - k)) % arr[j] == 0){
                        mn = min(mn,dp[i ^ j2][k] + abs(j - k));
                        //cout << dp[i ^ j2][k] << ' ' << abs(j - k) << ' ' << arr[j] << ' ' << ((dp[i ^ j2][k] + abs(j - k)) / arr[j] + 1) * arr[j] << '\n';
                    }else{
                        int c = (dp[i ^ j2][k] + abs(j - k)) / arr[j];
                        mn = min(mn,(c + 1) * arr[j]);

                        //cout << dp[i ^ j2][k] << ' ' << abs(j - k) << ' ' << arr[j] << ' ' << (c + 1) * arr[j] << '\n';
                    }
                }
                dp[i][j] = mn;
            }
        }
    }

    /*
    for(int i = 0; i < n2; i ++){
        for(int j = 0; j <= n; j ++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    
    int ans = 1e9;
    for(int i = 1; i <= n; i ++){
        ans = min(ans,dp[n2 - 1][i]);
    }
    cout << ans << '\n';

    return 0;
    
}