#include <iostream> 

using namespace std;

int main(){

    long long int a, b, c;

    while(cin >> a >> b >> c){

        if((a + b) <= c || (b + c) <= a || (a + c) <= b){
            cout << "BYE" << "\n";
        }else{
            cout << "SAFE" << "\n";
        }
    }

    return 0;
    
}