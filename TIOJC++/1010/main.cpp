#include <bits/stdc++.h> 

using namespace std;

int main(){

    string a, b;
    cin >> a >> b;

    int sum = 0;
    for(int i = 1; i <= min(a.size(),b.size()); i++){
        if(a.substr(0,i) == b.substr(b.size() - i,i)) sum = i;
    }
    cout << sum << '\n';

    return 0;
    
}