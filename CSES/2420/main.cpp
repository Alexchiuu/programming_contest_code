#include <bits/stdc++.h> 
#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int mod = 1e9 + 7;

signed main(){

    fastio

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = 'a' + s;
    int k, a;
    while(m --){
        cin >> k >> a;
        if(k == 1){
            char b;
            cin >> b;
            s[a] = b;
        }else{
            int c;
            cin >> c;
            int mid = (a + c) / 2;
            int suma = 0, sumb = 0;
            if((a + c) % 2 == 0){
                int o = 1;
                for(int i = mid - 1; i >= a; i --){
                    suma = (suma + ((s[i] - 'a') * o) % mod) % mod;
                    o = o * 127 % mod;
                }
                o = 1;
                for(int i = mid + 1; i <= c; i ++){
                    sumb = (sumb + ((s[i] - 'a') * o) % mod) % mod;
                    o = o * 127 % mod;
                }
            }else{
                int o = 1;
                for(int i = mid; i >= a; i --){
                    suma = (suma + ((s[i] - 'a') * o) % mod) % mod;
                    o = o * 127 % mod;
                }
                o = 1;
                for(int i = mid + 1; i <= c; i ++){
                    sumb = (sumb + ((s[i] - 'a') * o) % mod) % mod;
                    o = o * 127 % mod;
                }
            }
            if(suma == sumb){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
    
    return 0;    
}