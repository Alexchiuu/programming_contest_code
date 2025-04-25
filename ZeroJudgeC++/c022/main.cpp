#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    int a, b;
    for(int i = 1; i <= T; i ++){
        cin >> a >> b;
        a = a + !(a % 2);
        b = b - !(b % 2);
        cout << "Case " << i << ": " << (a + b) * ((b - a) / 2 + 1) / 2 << '\n';
    }

    return 0;
}