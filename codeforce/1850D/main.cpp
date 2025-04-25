#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    cin >> N;
    for(int v = 0; v < N; v ++){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int j = 0; j < n; j ++){
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end());
        int cnt = 1, ans = 0;
        for(int i = 1; i < n; i ++){
            if(arr[i] - arr[i - 1] <= k){
                cnt ++;
            }else{
                ans = max(ans,cnt);
                cnt = 1;
            }
        }
        ans = max(ans,cnt);
        cout << n - ans << '\n';
    }

    return 0;
}