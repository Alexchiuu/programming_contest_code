#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n - i - 1; j ++){
            putchar('_');
        }
        for(int j = 0; j <= i; j ++){
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}