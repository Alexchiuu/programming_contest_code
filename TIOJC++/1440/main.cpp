#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<pair<long long,long long>> bc(m);
    for(int i = 0; i < m; i++) cin >> bc[i].first >> bc[i].second;
    sort(a.begin(), a.end());
    sort(bc.begin(),bc.end());

    long long sum = 0;
    bool check = false;
    for(int i = 0, j = 0; i < n; i++, j++){
        while(j != m && a[i] > bc[j].first) j ++;
        if(j == m) break;
        if(i == n - 1) check = true;
        sum += bc[j].second;
    }
    if(check) cout << sum << '\n';
    else cout << "Impossible." << '\n';

    return 0;
    
}