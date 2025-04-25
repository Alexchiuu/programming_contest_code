#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 100;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t --){   
        int n;
        cin >> n;
        vector<int> arr(MAX);
        int input;
        int mx = 0;
        for(int i = 0; i < n; i ++){
            cin >> input;
            arr[input + 50010] ++;
            mx = max(mx,arr[input + 50010]);
        }
        if(mx > n / 2){
            cout << "No\n";
        }else cout << "Yes\n";
    }
    return 0;
}