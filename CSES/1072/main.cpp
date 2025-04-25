#include <bits/stdc++.h> 

using namespace std;

int main(){

    int k;

    cin >> k;
    long long ans;
    for(long long n = 1; n <= k ; n ++ ){
        ans = 0.5 * ( n * n * n * n - n * n) - ( 4 * n * n - 12 * n + 8);
        cout << ans << endl;
    }

    return 0;
    
}