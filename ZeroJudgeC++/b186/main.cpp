#include <bits/stdc++.h>

using namespace std;

int main(){

    long long a, b, c;
    while(cin >> a >> b >> c) cout << a << " 個餅乾，" << b + min(a/10,c/2) << " 盒巧克力，" << c << " 個蛋糕。\n";

    return 0;
}