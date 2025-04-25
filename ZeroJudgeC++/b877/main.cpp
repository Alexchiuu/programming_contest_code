#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int ans = a < b?b - a:100 + b - a;
    cout << ans << '\n';

    return 0;
}