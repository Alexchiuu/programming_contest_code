#include <iostream> 

using namespace std;

int hcf(int a,int b,int l){
    if(a == 0 || b == 0){
        return l;
    }if(a > b){
        l = b;
        a = a % b;
    }else if(b > a){
        l = a;
        b = b % a;
    }else{
        return a;
    }
    return hcf(a, b, l);
}

int main(){

    int a, b;
    while(cin >> a >> b){
        cout << hcf(a, b, 1) << endl;

    }

    return 0;
    
}