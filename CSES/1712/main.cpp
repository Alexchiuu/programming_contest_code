#include <bits/stdc++.h> 
 
using namespace std;
 
const int largeint = 1E9 + 6;
 
long long powab(int a,int b,int p){
    if(b == 0) return 1;
    if(b == 1) return a;
    long long x = powab(a,b/2,p);
    if(b % 2 == 1) return (a * x) % p * x % p;
    else return (x * x) % p;
}
 
int main(){
 
    int n;
    cin >> n;
    int a, b, c;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        cout << powab(a,powab(b,c,largeint),largeint+1) << endl;
    }
 
    return 0;
    
}