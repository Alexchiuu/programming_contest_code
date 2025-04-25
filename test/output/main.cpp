#include <bits/stdc++.h> 

#pragma GCC optimize("Ofast")

using namespace std;

double dp[100][101];

int main(){

    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[0][2] = 1.0/3;
    dp[0][3] = 1.0/3;

    double sum = 0;

    for(int i = 1; i < 50; i ++){
        for(int j = 1; j <= i + 3; j ++){
            dp[i][j] = dp[i - 1][j] * 2 / 3 + dp[i][j - 1] / 3;
            if(j == i + 3){
                sum += dp[i][j];
                dp[i][j] = 0;
            }
        }
    }
    
    for(int j = 0; j < 10; j ++){
        for(int i = 0; i < 10; i ++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << sum << '\n';
    return 0;
    
}
