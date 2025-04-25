#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n;
    while(cin >> n){
        if(n < 21){
            cout << "-1\n";
        }else if(n == 21){
            cout << "1\n";
        }
    }

    return 0;
}