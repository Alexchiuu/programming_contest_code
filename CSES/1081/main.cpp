#include <bits/stdc++.h>
using namespace std;
  
int n, num, a[1000005];
  
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num;
        a[num]++;
    }
    int mx = 1;
    for (int i = 2; i < 1000005; i++){
        int cnt = 0;
        for (int j = i; j < 1000005; j += i){
            cnt += a[j];
        }
        if (cnt >= 2) mx = i;
    }
    cout << mx << "\n";
}