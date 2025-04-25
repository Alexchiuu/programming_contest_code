#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

using namespace std;

signed main(){


    
    int n;
    cin >> n;
    int sum = 0, mx = 0;
    int input;
    for(int i = 0; i < n; i ++){
        cin >> input;
        sum += input;
        mx = max(mx, input);
    }
    cout << max(sum,mx * 2)<< '\n';

    return 0;    
}