#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){

    int N, K, P;
    cin >> N >> K >> P;

    vector<int> c(N + 1);
    vector<vector<int> > a(N + 1, vector<int> (5));
    vector<int> dp(55556, 1000000);
    dp[0] = 0;
    for(int i = 1; i <= N; i ++){
        cin >> c[i];
        for(int j = 0; j < K; j ++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= N; i ++){
        int sum = 0;
        for(int j = P; j >= a[i][0]; j --){
            sum += j * 10000;
            for(int k = P; k >= a[i][1]; k --){
                sum += k * 1000;
                for(int l = P; l >= a[i][2]; l --){
                    sum += l * 100;
                    for(int m = P; m >= a[i][3]; m --){
                        sum += m * 10;
                        for(int n = P; n >= a[i][4]; n --){
                            sum += n;
                            int tmp = sum - a[i][0] * 10000 - a[i][1] * 1000 - a[i][2] * 100 - a[i][3] * 10 - a[i][4] * 1;
                            dp[sum] = min(dp[sum],dp[tmp] + c[i]);
                            if (i == 1) cout << "dp["<< sum << "]=" << dp[sum] << '\n';
                            sum -= n;
                        }
                        sum -= m * 10;
                    }
                    sum -= l * 100;
                }
                sum -= k * 1000;
            }
            sum -= j * 10000;
        }
    }
    cout << dp[P * 11111] << '\n';

    return 0;
}