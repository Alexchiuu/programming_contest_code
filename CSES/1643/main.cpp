#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long mx = -1000000000;
    long long sum = 0;
    for(int i = 0 ; i < n; i++){
        int input;
        cin >> input;
        sum += input;
        mx = max(mx,sum);
        if(sum < 0) sum = 0;
    }
    cout << mx << '\n';

    return 0;
    
}