#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

using namespace std;

int bs(vector<int>& a,int x, int l, int r, int k, int mn){

    //cout << x <<  l <<  r <<  k <<  mn << '\n';
    int mid = (l + r)/ 2;
    mn = min(mn,abs(a[mid]*x - k));
    if(l == r) return mn;

    if (a[mid]*x > k){
        return bs(a,x,l,mid, k, mn);
    }
    else{
        return bs(a,x,mid + 1,r, k, mn);
    }
    return mn;
}

signed main(){
    fastio;

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];

    int l = 0, r = n - 1;
    for(int i = 0; i < n; i ++){
        if(arr[l] < arr[r]){
            a[i] = arr[l];
            l ++;
        }else{
            a[i] = arr[r];
            r --;
        }
    }


    int mn = 1e18;
    for(int i = 0; i < n; i ++){
        mn = min(mn,bs(a,a[i],0,n - 1,k,mn));
    }
    cout << mn << '\n';
    return 0;
}