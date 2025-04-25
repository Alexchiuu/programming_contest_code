#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 2e5 + 10;
vector<int> arr(MAX);

int solve(int ind,int n){
    //cout << "aaa" << ind << ' ' << n << '\n';
    vector<int>::iterator it = lower_bound(arr.begin() + ind, arr.begin() + n + 1, arr[ind] * 2);
    //cout << "bbb" << it - arr.begin() << '\n';
    if(it == arr.begin() + n + 1) return -1;
    //cout << "ccc" << *it << ' ' << *(it - 1) << '\n';
    if(*it == *(it - 1) * 2){
        return it - arr.begin();
    }else{
        return solve(it - arr.begin(), n);
    }
}

signed main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int sum = 0;
    int input;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    while(q --){
        int a, b;
        cin >> a >> b;
        int addon = b - (arr[a] - arr[a - 1]);
        for(int i = a; i <= n; i ++){
            arr[i] += addon;
        }
        cout << solve(1, n) << '\n';
    }

    return 0;
}