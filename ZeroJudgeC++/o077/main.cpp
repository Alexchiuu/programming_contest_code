#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }

    int mx = 0;
    for(int i = 0; i < n; i ++){

        int tmp = 1;
        if(i + 1 == n) break;

        while(i < n - 1 & a[i + 1] < a[i]){
            tmp ++;
            i ++;
        }
        mx = max(tmp,mx);
    }

    cout << mx << '\n';

    return 0;
}