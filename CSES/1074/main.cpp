#include <bits/stdc++.h> 

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    long long ans = 0;
    for(auto &a: arr){
        ans += abs(arr[n / 2] - a);
    }
    cout << ans << endl;
    return 0;
    
}