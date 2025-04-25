#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, k;
    cin >> n >> k;

    stack<int> mn;
    stack<int> mx;

    vector<int> arr(n + 1);


    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
    }

    sort(arr.begin() + 1, arr.begin() + k + 1);

    int mid;

    if(k%2 == 0){
        for(int i = k/2 - 1; i > 0; i --){
            mn.push(arr[i]);
        }
        for(int i = k/2 + 1; i <= k; i ++){
            mx.push(arr[i]);
        }
        mid = arr[k/2];
    }else{
        for(int i = k/2; i > 0; i --){
            mn.push(arr[i]);
        }
        for(int i = k/2 + 2; i <= k; i ++){
            mx.push(arr[i]);
        }
        mid = arr[k/2] + 1;
    }

    for(int i = k + 1; i <= n; i++){
        int tmp = (i - k);

    }

    cout << arr[k/2 + 1] << '\n';

    return 0;
}