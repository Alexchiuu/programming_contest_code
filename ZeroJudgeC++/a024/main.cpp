#include <bits/stdc++.h> 

using namespace std;

int main(){

    int a,b;
    cin>>a>>b;
    while(a != 0 && b != 0)
    {   
        if(a>b){
            a=a%b;
        }else if(a < b){
            b=b%a;
        }else{
            break;
        }
    }
    if(a == 0){
        cout << b << '\n';
    }else cout << a << '\n';
    return 0;
}