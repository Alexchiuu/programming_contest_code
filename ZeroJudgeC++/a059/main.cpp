#include <iostream> 
#include <math.h>

using namespace std;

bool isperfsq(int);

int main(){

    int times {}, a {}, b {};
    cin >> times;

    for(size_t i = 1; i <= times; i++){
        int sum = 0;
        cin >> a >> b;
        for(size_t j = a; j <= b; j++){
            if(isperfsq(j)){
                sum += j;
            }
        }
        cout << "Case " << i << ": " << sum << endl;
    }

    return 0;
    
}

bool isperfsq(int num){

    double checkmod;
    checkmod = sqrt(num);

    if(checkmod - int(checkmod) == 0){
        return true;
    }
    else{
        return false;
    }
}