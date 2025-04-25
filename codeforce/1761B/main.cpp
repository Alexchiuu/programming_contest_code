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
        for(int i = 0; i < n; i++) cin >> arr[i];
        bool check = false;
        if(n % 2 == 0 && n != 2){
            for(int i = 0; i + 3 < n; i += 2){
                if(arr[i] != arr[i + 2] || arr[i + 1] != arr[i + 3]){
                    check = true;
                    break;
                }
            }
        }else{
            check = true;
        }
        if(check) cout << n << '\n';
        else cout << n - (n / 2) + 1 << '\n';
    }

    return 0;
}