#include <bits/stdc++.h> 

using namespace std;

const int MAX = 2e5 + 10;

int st[MAX * 4];
int arr[MAX];

void build(int ind, int l, int r){
    if(l == r){
        st[ind] = arr[l];
    }else{
        int mid = (l + r) / 2;
        int lt = ind * 2, rt = lt + 1;
        build(lt,l,mid);
        build(rt,mid + 1,r);
        st[ind] = max(st[lt],st[rt]);
    }
}

int query(int ind,int l, int r, int x){
    if(l == r && ind == 1){
        if(x <= st[ind]) return 1;
        return 0;
    }
    if(l == r){
        st[ind] -= x;
        return l;
    }else{
        int ans = 0;
        int mid = (l + r) / 2;
        int lt = ind * 2, rt = lt + 1;
        if(x <= st[lt]){
            ans = query(lt,l,mid,x);
        }else if(x <= st[rt]){
            ans = query(rt,mid + 1,r,x);
        }else{
            return 0;
        }
        st[ind] = max(st[lt],st[rt]);
        return ans;
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    build(1,1,n);
    vector<int> ans(m);
    int q;
    for(int i = 0; i < m; i ++){
        cin >> q;
        ans[i] = query(1,1,n,q);
    }
    for(auto &a: ans){
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
    
}