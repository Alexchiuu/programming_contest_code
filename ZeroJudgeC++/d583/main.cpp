#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        int input;
        for(int i = 1; i <= n; i++) cin >> input;
        for(int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}