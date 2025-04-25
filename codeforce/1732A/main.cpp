#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        vector<int> arr(n);
        cin >> arr[0];
        int p = arr[0];
        for(int i = 1; i < n; i++){
            cin >> arr[i];
            p = __gcd(arr[i],p);
        }
        if(p == 1){
            cout << 0 << '\n';
            continue;
        }
        int bef = p;
        arr[n - 1] = __gcd(arr[n - 1],n);
        p = __gcd(p,arr[n - 1]);
        if(p == 1){
            cout << 1 << '\n';
            continue;
        }
        p = bef;
        arr[n - 2] = __gcd(arr[n - 2],n - 1);
        p = __gcd(p,arr[n - 2]);
        if(p == 1){
            cout << 2 << '\n';
        }else cout << 3 << '\n'; 
    }

    return 0;
    
}