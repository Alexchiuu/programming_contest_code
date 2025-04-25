#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    ll s,d,f;
    cin >> s >> f >> d;
    for(ll i = s; i != f; i += d) cout << i << ' ';
    cout << f << '\n';

    return 0;
}