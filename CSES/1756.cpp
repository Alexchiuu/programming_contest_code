#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    
    int a, b;
    while(m --){
        cin >> a >> b;
        if(a > b) swap(a,b);
        cout << a << ' ' << b << '\n';
    }   

   
    return 0;

}