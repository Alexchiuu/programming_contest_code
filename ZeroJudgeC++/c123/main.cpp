#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];;
    int k = 0;
    stack<int> s;
    for(int i = 1; i <= n; i ++){
        s.push(i);
        if(s.top() != arr[k]){
            
        }
    }

    return 0;
}