#include <bits/stdc++.h>

using namespace std;

int main(){

    long long H, M, S;
    cin >> H >> M >> S;
    M += S / 60;
    S %= 60;
    H += M / 60;
    M %= 60;
    H = H % 24;
    if(H < 10) cout << 0;
    cout << H << ':';
    if(M < 10) cout << 0;
    cout << M << ':';
    if(S < 10) cout << 0;
    cout << S << '\n';
    return 0;
}