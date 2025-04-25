#include <bits/stdc++.h> 

using namespace std;

const int MAX = 1e5 + 10;
const int INF = 1e9 + 10;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    vector<int> wei(n);
    vector<int> val(n);
    for(int i = 0;i < n; i ++){
        cin >> wei[i] >> val[i];
    }
    vector<int> dp(MAX,INF);
    dp[0] = 0;
    for(int i = 0; i < n; i ++){
        for(int j = MAX - 1; j - val[i] >= 0; j --){
            dp[j] = min(dp[j - val[i]] + wei[i],dp[j]);
        }
    }
    int ind = MAX - 1;
    while(dp[ind] > w) ind--;
    cout << ind << '\n';

    return 0;
    
}