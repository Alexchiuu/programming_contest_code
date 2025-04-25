#include <bits/stdc++.h> 
#define int long long

using namespace std;

const int MAX = 2e5 + 10;

int n, m;

vector<int> arr(MAX);

bool f(int t){
    //cout << "f:" << t << '\n';
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += t / arr[i];
        if(sum >= m) break;
        //cout << t / arr[i] << '\n';
    }
    return sum >= m;
}

int s(int l, int r){
    //cout << l << ' ' << r << '\n';
    if(l == r){
        return l;
    }else{
        int mid = (l + r) / 2;
        if(f(mid)) return s(l,mid);
        else return s(mid + 1, r);
    }
}

signed main(){

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.begin() + n);
    cout << s(0,arr[n - 1] * m) << '\n';

    return 0;
    
}