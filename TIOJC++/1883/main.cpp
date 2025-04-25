#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int w, b, n, m;
    while(t --){
        cin >> w >> b >> n;
        vector<int> a(n);
        vector<int> d(n);
        vector<int> dp(w + 1);
        for(int i = 0; i < n; i ++){
            cin >> a[i] >> d[i];
        }
        cin >> m;
        for(int i = 0; i < n; i ++){
            a[i] += m;
        }
        for(int i = 0; i <= w; i ++){
            for(int j = 0; j < a.size(); j ++){
                if(i - a[j] >= 0){
                    dp[i] = max(dp[i],dp[i - a[j]] + d[j]);
                }
            }
        }
        if(dp[w] > b) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
    
}