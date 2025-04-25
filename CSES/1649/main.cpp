#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast")
const int MAX = 2e5 + 1;

using namespace std;

struct node{
    int l,r;
    int lson,rson;
    int data;
};

node ST[2 * MAX];
int arr[MAX];

int stpt = 0;
void build(int l,int r,int index){
    ST[index].l = l;ST[index].r = r;
    if(l == r - 1){
        ST[index].data = arr[l];
    }else{
        int mid = (l + r) / 2;
        int lson = ST[index].lson = ++stpt;
        int rson = ST[index].rson = ++stpt;
        build(l,mid,lson);
        build(mid,r,rson);
        ST[index].data = min(ST[lson].data,ST[rson].data);
    }
}

void modify(int x,int v,int index){
    if(ST[index].l == ST[index].r - 1){
        ST[index].data = v;
    }else{
        int mid = (ST[index].l + ST[index].r) / 2;
        int rson = ST[index].rson;
        int lson = ST[index].lson;
        if(x < mid) modify(x,v,lson);
        else modify(x,v,rson);
        ST[index].data = min(ST[lson].data,ST[rson].data);
    }
}

int query(int l,int r,int index){
    if(ST[index].l == ST[index].r - 1){
        return ST[index].data;
    }else{
        int mid = (ST[index].l + ST[index].r) / 2;
        int lson = ST[index].lson;
        int rson = ST[index].rson;
        if(r <= mid) return query(l,r,lson);
        else if(l >= mid) return query(l,r,rson);
        else return min(query(l,mid,lson),query(mid,r,rson));
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) cin >> arr[i];

    build(0,n,0);

    int a, b, c;
    for(int i = 0; i < q; i++){
        cin >> a >> b >> c;
        if(a == 1){
            modify(b - 1,c,0);
        }else if(a == 2){
            cout << query(b - 1,c,0) << '\n';
        }
    }

    return 0;
    
}