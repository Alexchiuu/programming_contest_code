#include <iostream> 

using namespace std;

int main(){

    int A, B;

    cin >> A >> B;
    if(A < B){
        for(int i = A; i <= B; i++){
            for(int j = 0; j < i; j++){
                cout << "*";
            }
            cout << endl;
        }
    }else{
        for(int i = A; i >= B; i--){
            for(int j = 0; j < i; j++){
                cout << "*";
            }
            cout << endl;
        }
        
    }

    return 0;
    
}