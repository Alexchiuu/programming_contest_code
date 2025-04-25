#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    long long ans = 0;
    long long sum = 0;
    int d, f;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> f >> d;
        arr[i] = f;
        ans += d - f;
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        ans -= sum;
        sum += arr[i];
    }
    cout << ans << '\n';

    return 0;
}