#include <bits/stdc++.h> 
#define int long long

using namespace std;

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int a, p, ind;
    while(q--){
        ind = 0;
        cin >> a >> p;
        vector<int>::iterator it = arr.begin();
        while(it - arr.begin() < p){
            //cout << "find:" << arr[ind] + a << '\n';
            it = upper_bound(arr.begin() + ind,arr.end(),arr[ind] + a);
            //cout << "found:" << *it << '\n';
            if(it >= arr.begin() + p){
                a = max(arr[ind] + a,arr[p]) - min(arr[ind] + a,arr[p]);
                break;
            }else{
                a = *it - arr[ind] - a;
                ind = it - arr.begin();
            }
        }
        cout << a << '\n';
    }

    return 0;
    
}