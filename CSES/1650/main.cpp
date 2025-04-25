#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAX = 2e5 + 10;

long long st[MAX * 4];
 
void modify(int index, int l, int r, int arrin, int n){
    if(l == r){
        st[index] = n;
    }else{
        int mid = (l + r) / 2;
        int lson = index * 2, rson = lson + 1;
        if(arrin <= mid) modify(lson,l,mid,arrin,n);
        else modify(rson,mid + 1,r,arrin,n);
        st[index] = st[lson] ^ st[rson];
    }
}
 
long long query(int index, int l, int r, int ql, int qr){
    if(l == ql && r == qr){
        return st[index];
    }else{
        int mid = (l + r) / 2;
        int lson = index * 2, rson = lson + 1;
        if(qr <= mid) return query(lson,l,mid,ql,qr);
        else if(ql > mid) return query(rson,mid + 1,r,ql,qr);
        else return query(lson,l,mid,ql,mid) ^ query(rson,mid + 1,r,mid + 1,qr);
    }
}

signed main(){

    fastio

    int n, m;
    cin >> n >> m;
    int input;
    for(int i = 1; i <= n; i ++){
        cin >> input;
        modify(1,1,n,i,input);
    }
    int a, b;
    for(int i = 0; i < m; i ++){
        cin >> a >> b;
        cout << query(1,1,n,a,b) << '\n';
    }

    return 0;    
}