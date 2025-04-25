#include <iostream> 

using namespace std;


int main(){

    size_t n;
    long int swap {},check {};
    while(cin >> n){
        long int inputar[n];
        
        for(int i = 0; i < n; i++){
            cin >> inputar[i];
        }
        check = 0;
        while(check != (n - 1)){
            check = 0;
            for(int i = 1; i < n; i++){
                if((inputar[i] % 10) < (inputar[i - 1] % 10)){
                    swap = inputar[i];
                    inputar[i] = inputar[i - 1];
                    inputar[i - 1] = swap;
                }else if((((inputar[i] % 10) == (inputar[i - 1] % 10)) && (inputar[i-1] < inputar[i]))){
                    swap = inputar[i];
                    inputar[i] = inputar[i - 1];
                    inputar[i - 1] = swap;
                }else{
                    check++;
                }
            }
        }
        for(auto a:inputar){
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
    
}