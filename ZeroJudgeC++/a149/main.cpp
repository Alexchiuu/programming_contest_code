#include <iostream> 

using namespace std;

int main(){

    int input {};
    size_t T {};
    cin >> T;
    for(size_t i = 0; i < T; i++){
        int sum = 1;
        cin >> input;

        if(input == 0){
            sum = 0;
        }
        while(input != 0){
            sum *= (input % 10);
            input /= 10;
        }
        cout << sum << endl;
    }

    return 0;
    
}