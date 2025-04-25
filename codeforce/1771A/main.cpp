#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    long long n;
    while(t --){
        cin >> n;
        int mx = 0;
        long long msx = 0;
        int mn = 1e6;
        long long msn = 0;
        int a;

        for(int i = 0; i < n; i++){
            cin >> a;
            if(a > mx){
                msx = 1;
                mx = a;
            }else if(a == mx){
                msx ++;
            }

            if(a < mn){
                msn = 1;
                mn = a;
            }else if(a == mn){
                msn ++;
            }
        }
        if(mx == mn) cout << n * (n - 1) << '\n';
        else cout << msx * msn * 2 << '\n';
    }

    return 0;
}