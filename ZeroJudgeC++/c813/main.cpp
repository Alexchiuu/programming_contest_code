#include <bits/stdc++.h>

using namespace std;

int f(int n){
    if(n < 10) return n;
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return f(sum);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n != 0){
        cout << f(n) << '\n';
    }

    return 0;
}