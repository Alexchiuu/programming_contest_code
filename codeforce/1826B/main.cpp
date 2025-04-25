#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k, tmp = 0;
        cin >> k;
        vector<int> arr(k);
        for(int j = 0; j < k; j ++) cin >> arr[j];
        int gp = abs(arr[tmp] - arr[k - 1 - tmp]);
        /*
        while(gp == 0 && tmp <= k/2){
            tmp++;
            gp = abs(arr[tmp] - arr[k - 1 - tmp]);
        }
        if(tmp == k/2 + 1){
            cout << 0 << "aa" <<'\n';
            continue;
        }
        */
        for(int j = 1; j <= k / 2; j ++){
            if(arr[j] != arr[k - 1 - j]) gp = __gcd(gp,abs(arr[j] - arr[k - 1 - j]));
        }
        cout << gp << '\n';
    }

    return 0;
}