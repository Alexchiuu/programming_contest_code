#include <bits/stdc++.h>

using namespace std;

int st[2000000] = {};
int arr[500001] = {};

void build(int index, int l, int r){
    if(l == r){
        st[index] = arr[l];
    }else{
        int mid = (l + r) / 2;
        int lson = index * 2, rson = lson + 1;
        build(lson,l,mid);
        build(rson,mid + 1,r);
        st[index] = max(st[lson],st[rson]);
    }
}

int query(int index, int l, int r, int ql, int qr){
    if(ql == l && qr == r){
        return st[index];
    }else{
        int mid = (l + r) / 2;
        int lson = index * 2, rson = lson + 1;
        if(qr <= mid) return query(lson,l,mid,ql,qr);
        else if(ql > mid) return query(rson,mid + 1,r,ql,qr);
        else return max(query(lson,l,mid,ql,mid),query(rson,mid + 1,r,mid + 1,qr));
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int input;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    build(1,1,N);

    int m;
    cin >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cout << query(1,1,N,a,b) << '\n';
    }

    return 0;
}