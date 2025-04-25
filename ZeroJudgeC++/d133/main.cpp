#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    vector<long long> dp(30001);
    vector<int> coins = {1,5,10,25,50};
    dp[0] = 1;
    for(int i = 0; i < 5; i++) {
        for(int j = coins[i]; j <= 30000; j ++){
            dp[j] += dp[j - coins[i]];
        }
    }   
    int input;
    while(cin >> input){
        if(dp[input] == 1){
            cout << "There is only 1 way to produce " << input << " cents change." << '\n';
        }else{
            cout << "There are " << dp[input] << " ways to produce " << input << " cents change. " << '\n';
        }
    }
    return 0;
}