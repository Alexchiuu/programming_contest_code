#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        int LCF = arr[0];
        for(int i = 1; i < n; i++) LCF = __gcd(LCF,arr[i]);
        cout << arr.back() / LCF << '\n';
    }

    return 0;
}