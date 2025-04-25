#include <bits/stdc++.h> 
 
const int MAX = 1e6 + 10;
 
using namespace std;
 
int main(){
 
    vector<int> dp(MAX,10000000);
    for(int i = 0; i < 10; i++) dp[i] = 1;
    int n;
    cin >> n;
    for(int i = 10; i <= n; i++){
        int k = i;
        while(k != 0){
            int a = k % 10;
            k /= 10;
            dp[i] = min(dp[i],dp[i - a] + 1);
        }
    }
    cout << dp[n] << '\n';
 
    return 0;
    
}