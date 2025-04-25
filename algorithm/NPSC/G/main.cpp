#include <bits/stdc++.h> 

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
    int sum = 0;
    dp[0] = 1;
    int pw = 1;
    for(int i = 1; i < n; i++){
        cout << "aaa\n";
        for(int j = 0; j < i; j ++){
            if(arr[j] < arr[i]){
                sum += dp[i] + dp[i] - pw;
            }
        }
        cout << "bbb\n";
        for(int j = 0; j < i; j ++){
            dp[j] *= 2;
        }
        cout << "ccc\n";
        dp[i] = pw;
        cout << "eee\n";
        for(int j = 2; i - j >= 0; j += 2){
            dp[i - j] -= 1;
            dp[i - j + 1] ++;
        }
        cout << "ddd\n";
        for(int j = 0; j <= i; j ++){
            cout << dp[j] << ' ';
        }
        cout << '\n';
        pw *= 2;
    }
    cout << sum << '\n';
    return 0;
    
}