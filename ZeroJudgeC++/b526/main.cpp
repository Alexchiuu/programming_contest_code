#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(n + 1);
    int a, b;
    for(int i = 0; i < m * 2 ; i += 2){
        cin >> a >> b;
        arr.push_back(a);
        arr.push_back(b + 1);
    }
    sort(arr.begin(),arr.end());
    int sum = 0;
    for(int i = 0; i < m * 2 + 2; i += 2){
        sum += arr[i + 1] - arr[i];
    }
    cout << sum << '\n';

    return 0;
}