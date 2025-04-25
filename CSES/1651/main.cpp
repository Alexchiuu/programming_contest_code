#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

using namespace std;

const int MAX = 1e6;;

int st[MAX] = {};
int arr[MAX] = {};

void build(int l, int r, int ind){
    if(l == r){
        st[ind] = arr[l];
        return;
    }
    int mid = (l+r) /2;
    int lst = ind * 2, rst = ind * 2 + 1;
    build(l, mid, lst);build(mid + 1, r, rst);
    return;
}

void mani(int x, int l, int r, int ql, int qr, int ind){
    if(l == ql && r == qr){
        st[ind] += x;
        return;
    }
    int mid = (l+r) /2;
    int lst = ind * 2, rst = ind * 2 + 1;
    if(mid < ql) mani(x,mid + 1, r,ql,qr,rst);
    else if(mid >= qr) mani(x,l,mid,ql,qr,lst);
    else{
        mani(x,l,mid,ql,mid,lst);
        mani(x,mid+1,r,mid+1,qr,rst);
    }
}

int query(int n,int l, int r, int ind){
    if(l == r){
        return st[ind];
    }
    int mid = (l+r) /2;
    int lst = ind * 2, rst = ind * 2 + 1;
    if(n > mid) return st[ind] + query(n,mid + 1,r,rst);
    else if(n <= mid) return st[ind] + query(n,l,mid,lst);
}

signed main(){

    fastio

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
    }
    build(1,n,1);
    int k;
    while(q --){
        cin >> k;
        if(k == 1){
            int a, b, u;
            cin >> a >> b >> u;
            mani(u,1,n,a,b,1);
        }else{
            int a;
            cin >> a;
            cout << query(a,1,n,1) << '\n';
        }
    }

    return 0;    
}