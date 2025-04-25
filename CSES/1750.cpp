#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")

using namespace std;

int par[200010][30];

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++){
        cin >> par[i][0];
    }

    for(int i = 1; i < 30; i ++){
        for(int j = 1; j <= n; j ++){
            par[j][i] = par[par[j][i - 1]][i - 1];
            //cout << "par" << j <<' ' << par[j][i - 1] << ' ' << i << ' '  << par[j][i] << '\n';

        }
    }


    int a, b;
    while(m --){
        cin >> a >> b;
        int pow = 0;
        int tmp = a;
        while(b > 0){
            if(b % 2 == 1){
                tmp = par[tmp][pow];
            }
            pow ++;
            b >>= 1;
        }
        cout << tmp << '\n';
    }

    return 0;

}