#include <bits/stdc++.h> 

#pragma GCC optimize("Ofast")

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if(n <= 5000 && m <= 5000){
        vector<long long> w(n + 1);
        for(int i = 1; i <= n; i ++) cin >> w[i];
        int l, r, k;
        for(int i = 0; i < m; i ++){
            cin >> l >> r >> k;
            long long mx = w[l];
            int check = 1;
            for(int j = l; j <= r; j ++){
                if(w[j] < mx && mx + w[j] > k){
                    check = 0;
                    break;
                }
                mx = max(mx,w[j]);
            }
            if(check==0)putchar('0');
            else putchar('1');
            putchar('\n');
        }
    }else{
        
    }

    return 0;
    
}