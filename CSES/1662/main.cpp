#include <bits/stdc++.h> 

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> r(n);
    r[0] = 1;
    int input;
    long long sum = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        cin >> input;
        sum += input;
        int k = sum % n;
        if(k < 0) k += n;
        ans += r[k];
        r[k]++;
    }
    cout << ans << '\n';

    return 0;
    
}