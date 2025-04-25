#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t --){
        long long l, r, x;
        cin >> l >> r >> x;
        long long a, b;
        cin >> a >> b;
        if(a == b){
            cout << 0 << '\n';
        }else if(abs(a - b) >= x){
            cout << 1 << '\n';
        }else if(a + x + abs(a - b) <= r || a - x - abs(a - b) >= l || (abs((a + x) - b) >= x && a + x <= r) || (abs((a - x) - b) >= x && a - x >= l)){
            cout << 2 << '\n';
        }else{
            if(a + x <= r){
                a += x;
                if(a + x + abs(a - b) <= r || a - x - abs(a - b) >= l || (abs((a + x) - b) >= x && a + x <= r) || (abs((a - x) - b) >= x && a - x >= l)){
                    cout << 3 << '\n';
                    continue;
                }
                a -= x;
            }
            if(a - x >= l){
                a -= x;
                if(a + x + abs(a - b) <= r || a - x - abs(a - b) >= l || (abs((a + x) - b) >= x && a + x <= r) || (abs((a - x) - b) >= x && a - x >= l)){
                    cout << 3 << '\n';
                    continue;
                }
            }
            cout << -1 << '\n';
        }
    }

    return 0;
}