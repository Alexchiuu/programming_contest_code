#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> buyers(n);
    vector<int> prices(m);
    for(int i = 0; i < n; i++) cin >> buyers[i];
    for(int i = 0; i < m; i++) cin >> prices[i];
    sort(buyers.begin(),buyers.end());
    sort(prices.begin(),prices.end());
    int i = 0, j = 0;
    int ans = 0;
    while(i < n && j < m){
        if(abs(buyers[i]-prices[j]) <= k){
            i ++;
            j ++;
            ans ++;
        }else if(buyers[i] < prices[j]){
            i ++;
        }else{
            j ++;
        }
    }
    cout << ans << '\n';
    return 0;
    
}