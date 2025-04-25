#include <bits/stdc++.h>

using namespace std;

int main(){

    int i, j ,k;
    cin >> i >> j >> k;
    bool a,b,c;
    a = i != 0, b = j != 0, c = c != 0;
    bool check = false;
    if(a && b == c){      
        check = true;
        cout << "AND\n";
    }
    if(a || b == c){
        check = true;
        cout << "OR\n";
    }
    if(a ^ b == c){
        check = true;
        cout << "XOR\n";
    }
    if(!check){
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}