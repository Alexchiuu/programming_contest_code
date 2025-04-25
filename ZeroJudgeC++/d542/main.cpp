#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1000000;

ll arr[N],sub[N];

ll mergecount(int l, int r){
    if(l == r) return 0;
    ll mid = l + (l + r) / 2;
    ll sum = mergecount(l,mid) + mergecount(mid + 1,r);
    for(int i = l; i <= r; i++) sub[i] = arr[i];
    int x = l, y = mid + 1, cur = l;
    while(x <= mid && y <= r){
        if(sub[x] <= sub[y]){
            arr[cur] = sub[x];
            x ++;
        }else{
            arr[cur] = sub[y];
            y ++;
            sum += mid - x + 1;
        }
        cur ++;
    }
    while(x <= mid){
        arr[cur] = sub[x];
        x ++;
        cur ++;
    }
    while(y <= r){
        arr[cur] = sub[y];
        y ++;
        cur ++;
    }
    return sum;
}


int main(){

    int n;
    while(cin >> n){
        for(int i = 0; i < n;i++){
            cin >> arr[i];
        }
        cout << mergecount(0,n - 1) << '\n';
    }

    return 0;
}