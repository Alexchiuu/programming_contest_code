#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    while(cin >> n >> k){
        if(k != 0 && n % k == 0) cout << "Ok!" << '\n';
        else if(k == 0 && n == 0) cout << "Ok!" << '\n';
        else cout << "Impossib1e!" << '\n';
    }

    return 0;
}