#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> mon(n);
    for(int i = 0; i < n; i++) cin >> mon[i];
    for(int i = 0; i < n && mon[i] < k; i++) k += mon[i];
    cout << k << '\n';

    return 0;
}