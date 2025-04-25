#include <bits/stdc++.h> 

using namespace std;

const int largeint = 1E9 + 7;

long long powab(int a,int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    long long x = powab(a,b/2);
    if(b % 2 == 1) return (a * x) % largeint * x % largeint;
    else return (x * x) % largeint;
}

int main(){

    int n;
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cout << powab(a,b) << endl;
    }

    return 0;
    
}