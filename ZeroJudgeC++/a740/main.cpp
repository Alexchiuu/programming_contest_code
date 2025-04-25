#include <iostream> 
#include <math.h>

using namespace std;

bool isPrime(int n){
    if(n == 2 || n == 3){
        return true;
    }
    int m = n % 6;
    if(!(m == 1 || m == 5)){
        return false;
    }
    for(int i = 5; i <= sqrt(n); i++){
        if(n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }
    return true;  
}
int sumoff(int n){
    if(isPrime(n)){
        return n;
    }
    for(int i = 2; i <= sqrt(n); i ++){
        if(n % i == 0){
            return sumoff(n / i) + sumoff(i);
        }
    }
}

int main(){

    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n){
        cout << sumoff(n) << "\n";
    }

    return 0;
    
}