#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > sum + 1) break;
        sum += arr[i];
    }
    cout << sum + 1 << '\n';
    return 0;
    
}