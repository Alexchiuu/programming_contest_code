#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int a , b , c , d ;
    cin >> a >> b >> c >> d ;
    for(int i=a ; i >= 1 ; i--){
        if (i!=b && i!=c && i!=d) cout << "No. " << i << '\n';
    }
    return 0;
}