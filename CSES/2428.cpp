#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, k;
    cin >> n >> k;

    map<int,int> mp;
    vector<int> arr(n + 1);


    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
    }

    int j = 0;
    int sum = 0;
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(mp[arr[i]] == 0) sum ++;
        mp[arr[i]] ++;

        while(sum > k){
            j ++;
            mp[arr[j]]--;
            if(mp[arr[j]] == 0){
                sum --;
            }
        }
        ans += i - j;
    }

    cout << ans << '\n';

    return 0;
}