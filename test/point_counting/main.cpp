#include <bits/stdc++.h> 
#define int long long

#pragma GCC optimize("Ofast")

using namespace std;

signed main(){

    int sum = 0;
    for(int i = 1e8; i < 3e8; i ++){
        int two = 0;
        int zero = 0;
        int four = 0;
        int save = i;
        while(save > 0){
            int k = save % 10;
            save /= 10;
            if(k == 2){
                two ++;
            }
            if(k == 4){
                four ++;
            }
            if(k == 0){
                zero ++;
            }
        }
        if(two > 1 && zero > 0 && four > 0){
            sum ++;
        }
    }

    cout << double(double(sum) / 2e8) << '\n';
    return 0;
    
}