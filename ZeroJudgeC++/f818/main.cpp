#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a = 20000, b = 20000;
    int x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x * arr[i] < a * b){
            a = x;
            b = arr[i];
        }
    }
    cout << b << ' ' << a << '\n';

    return 0;
}