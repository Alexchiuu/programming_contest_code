#include <bits/stdc++.h> 

using namespace std;

const int MAX = 2e5 + 10;

long long arr[MAX];

bool bs(long long n,int l, int r, int x){
    if(l == r){
        if(n - arr[l - 1] == x) return true;
        else return false;
    }
    int mid = (l + r) / 2;
    if(n - arr[mid - 1] > x) return bs(n,mid + 1,r,x);
    return bs(n,l,mid,x);
}

int main(){

    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(bs(arr[i],1,i,x)) ans++;
    }
    cout << ans << '\n';
    return 0;
    
}