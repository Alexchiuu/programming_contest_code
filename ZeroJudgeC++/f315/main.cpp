#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAX = 1e5 + 10;

int st[MAX * 8] = {};

void modify(int index, int l, int r, int x){
    if(l == r){
        st[index]++;
    }else{
        int mid = (l + r) / 2;
        int lson = index * 2,rson = index * 2 + 1;
        if(x <= mid) modify(lson,l,mid,x);
        else modify(rson,mid + 1,r,x);
        st[index] = st[lson] + st[rson];
    }
}

int query(int index, int l, int r, int ul, int ur){
    if(l == ul && r == ur){
        return st[index];
    }else{
        int mid = (l + r) / 2;
        int lson = index * 2,rson = index * 2 + 1;
        if(ur <= mid) return query(lson,l,mid,ul,ur);
        else if(ul > mid) return query(rson,mid + 1,r,ul,ur);
        else return query(lson,l,mid,ul,mid) + query(rson,mid + 1,r,mid + 1,ur);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll sum = 0;
    vector<pair<int,int>> arr(n + 1,{-1,-1});
    int input;
    for(int i = 0; i < n * 2; i++){
        cin >> input;
        if(arr[input].first == -1) arr[input].first = i;
        else arr[input].second = i;
    }
    for(int i = 1; i <= n; i++){
        sum += query(1,0,n * 2 - 1,arr[i].first,arr[i].second);
        modify(1,0,n * 2 - 1,arr[i].first);
        modify(1,0,n * 2 - 1,arr[i].second);
    }

    cout << sum << '\n';

    return 0;
}