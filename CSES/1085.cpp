#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mx = 2e5 + 10;

int arr[mx] = {};
int n, k;

bool check(int x){
    int tmp = 1;
    int cur = 0;
    for(int i = 0; i < n; i ++){
        cur += arr[i];
        if(cur > x){
            cur = arr[i];
            tmp ++;
            if(tmp > k){
                return false;
            }
        }
    }
    return true;
}

int bs(int l, int r){
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(check(mid)){
        return bs(l, mid);
    }else{
        return bs(mid + 1, r);
    }
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int sum = 0;
    
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        sum += arr[i];
    }

    cout << bs(1,sum + 5) << '\n';

    return 0;
}