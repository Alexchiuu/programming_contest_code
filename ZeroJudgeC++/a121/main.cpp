#include <iostream> 
#include <math.h>

using namespace std;

bool isprime(int);

int main(){

    int a {}, b {};
    
    while(cin >> a >> b){
        int count {};
        for(size_t i = a; i <= b; i++){
            if(a > b){
                count == 0;
                break;
            }
            if(isprime(i)){
                count += 1;
            }
        }
        cout << count << endl;
    }

    return 0;
    
}

bool isprime(int num){

    if(num == 2 || num == 3){
        return true;
    }else if(num % 2 == 0 || num == 1){
        return false;
    }else if(num % 6 == 1 || num % 6 == 5){

        for(int i = 3; i <= sqrt(num); i += 2){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}