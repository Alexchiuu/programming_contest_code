#include <bits/stdc++.h> 
#define int long long

using namespace std;

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, k;
    cin >> x >> k;
    priority_queue<int, vector<int>, greater<int> > pq;
    int input;
    for(int i = 0; i < k; i ++){
        cin >> input;
        pq.push(input);
    }
    int ans = 0;
    while(pq.size() > 1){
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();
        pq.push(a + b);
        ans += a + b;
    }
    cout << ans << '\n';

    return 0;
    
}