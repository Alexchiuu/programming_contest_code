#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    while(cin >> a >> b){
        cout << (b[0] - a[0] + 26) % 26 << '\n';
    }

    return 0;
}