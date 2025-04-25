#include<bits/stdc++.h>

using namespace std;

int main(){

    int mx = 0;
    int cur = 1;
    int n, input, lst;
    cin >> n;
    cin >> lst;
    for(int i = 1; i < n; i++){
        cin >> input;
        if(input < lst) cur ++, mx = max(mx,cur);
        else cur = 1;
        lst = input;
    }
    cout << mx << '\n';

    return 0;

}