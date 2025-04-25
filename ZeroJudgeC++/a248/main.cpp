#include <iostream> 

using namespace std;

int main(){

    unsigned int a, b, N, carry;
    while(cin >> a >> b >> N){
        cout << a / b;
        carry = a % b;
        cout << '.';
        for(size_t i = 0; i < N; i ++){
            carry *= 10;
            cout << carry / b;
            carry = carry % b;
        }
        cout << endl;
    }

    return 0;
    
}