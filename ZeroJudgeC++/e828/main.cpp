#include <bits/stdc++.h>

using namespace std;


const int INF = 2e9;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string cmp;
    cin >> cmp;
    string input;
    int mnd = INF;
    int mni = 0;
    for(int i = 1; i <= 3; i ++){
        cin >> input;
        vector<int> dp(input.size() + 1);
        for(int j = 0; j <= input.size(); j ++) dp[j] = j * 2;
        for(int j = 1; j <= cmp.size(); j ++){
            vector<int> dp2(input.size() + 1);
            dp2[0] = j * 2;
            for(int k = 1; k <= input.size(); k ++){
                dp2[k] = min(dp[k - 1] + !(cmp[j - 1] == input[k - 1]) * 3,min(dp[k] + 2,dp2[k - 1] + 2));
            }
            for(int k = 0; k <= input.size(); k ++) dp[k] = dp2[k];
        }
        if(dp[input.size()] <= mnd){
            mnd = dp[input.size()];
            mni = i;
        }
    }
    cout << mni << ' ' << mnd << '\n';

    return 0;
}