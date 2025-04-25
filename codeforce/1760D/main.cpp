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
        vector<int> ter(n);
        for(int i = 0; i < n; i++) cin >> ter[i];
        int l = 0;
        int r = n - 1;
        for(int i = 1; i < n; i ++){
            if(ter[i] <= ter[i - 1]) l = i;
            else break;
        }
        for(int i = n - 2; i >= l; i --){
            if(ter[i] <= ter[i + 1]) r = i;
            else break;
        }
        if(l != r) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}