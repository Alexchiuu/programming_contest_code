#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = 0;
    stack<int> s;
    s.push(arr[m - 1]);
    for(int i = m - 1; i < n; i ++){
        if(arr[i] > s.top()) s.push(arr[i]);
    }
    ans += s.size() - 1;
    stack<int> s1;
    s1.push(arr[m - 1]);
    for(int i = m - 1; i >= 0; i --){
        if(arr[i] > s1.top()) s1.push(arr[i]);
    }
    ans += s1.size() - 1;
    cout << ans << '\n';
    return 0;
}