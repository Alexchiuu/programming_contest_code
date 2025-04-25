#include <bits/stdc++.h> 
 
using namespace std;
 
const int MAX = 2e5 + 10;
int n, q;

int h[MAX];
int w[MAX];
int st1[MAX * 4];
int st[MAX * 4];
 
void modify1(int index, int l, int r, int arrin, int x){
    if(l == r){
        st[index] = arrin;
    }else{
        int mid = (l + r) / 2;
        int lson = 2 * index, rson = lson + 1;
        if(arrin <= mid) modify1(lson,l,mid,arrin,x);
        else modify1(rson,mid + 1,r,arrin,x);
        if(h[st[lson]] > h[st[rson]]){
            st[index] = st[lson];
        }else{
            st[index] = st[rson];
        }
    }
}
 
int query1(int index, int l, int r, int ql, int qr){
    if(l == ql && r == qr){
        return st[index];
    }else{
        int mid = (l + r) / 2;
        int lson = 2 * index, rson = lson + 1;
        if(qr <= mid) return query1(lson,l,mid,ql,qr);
        else if(ql > mid) return query1(rson,mid + 1,r,ql,qr);
        else{
            int v = query1(lson,l,mid,ql,mid), b = query1(rson,mid + 1,r,mid + 1,qr);
            if(h[v] > h[b]){
                return v;
            }else{
                return b;
            }
        }
    }
}

 
int modify(int l, int r){
    cout <<"lr" << l << ' ' << r << '\n';
    if(l == r){
        st1[l] = w[l];
        cout << "st1[" << l << "]:"  << st1[l] << '\n';
        return st1[l];
    }
    int mid = query1(1,1,n,l,r);
    cout <<"mid" << mid << '\n';
    st1[mid] = w[mid];
    if(mid > l) st1[mid] += modify(l,mid - 1);
    if(mid < r) st1[mid] += modify(mid + 1,r);
    cout << "st1[" << mid << "]:"  << st1[mid] << '\n';
    return st1[mid];
}

 
int main(){
 
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        cin >> h[i];
        modify1(1,1,n,i,h[i]);
    }
    for(int i = 1; i < n * 4; i ++){
        cout << st[i];
    }


    for(int i = 1; i <= n; i ++) cin >> w[i];
    modify(1,n);
    for(int i = 1; i <= n; i ++) cout << st1[i] << ' ';
    cout << '\n';
    while(q --){
        int a, b, c;
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            w[b] = c;
            modify(1,n);
        }else{
            cin >> b;
            cout << st1[b] << '\n';
        }
    }
    return 0;
    
}