#include <iostream> 

using namespace std;

long long int f(long long int n);
long long int g(long long int n);
int main(){

    int n;
    while(cin >> n){

        cout << f(n) << ' ' << g(n) << endl;;

    }

    return 0;
    
}

long long int f(long long int n){
    if(n == 1){
        return 1;
    }else{
        return f(n - 1) + n;
    }
}

long long int g(long long int n){
    if(n == 1){
        return 1;
    }else{
        return f(n) + g(n - 1);
    }
}