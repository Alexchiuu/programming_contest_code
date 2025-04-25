#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAX = 2e4 + 1;

ll N, C;
ll arr[MAX];

bool tring(ll k){
    ll sum = 0;
    for(int i = 0; i < N; i ++){
        if(arr[i] > k) continue;
        sum += (k - arr[i]) * (k - arr[i]);
        if(sum > C) return false;
    }
    return true;
}

ll sch(ll l,ll r){
    if(l == r) return l;
    ll mid = (l + r) / 2 + 1;
    if(tring(mid)){
        return sch(mid, r);
    }else{
        return sch(l, mid - 1);
    }
}

int main(){

    cin >> N >> C;
    for(int i = 0; i < N; i++) cin >> arr[i];
    cout << sch(0,100000000) << '\n';

    return 0;
}