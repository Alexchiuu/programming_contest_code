#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    for(int j = 0; j < n; j ++){
        bool odd = true;
        int l = 0,min = 1000000000;
        cin >> l;
        int input;
        for(int i = 0; i < l; i ++){
            cin >> input;
            if(input < min) min = input;
            if(input % 2 == 1) odd = false; 
        }
        if(odd || min % 2 == 1) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}