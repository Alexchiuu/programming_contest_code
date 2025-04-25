#include <iostream> 

using namespace std;

int main(){

    int numbers [] {1,2,3,4,5,6,7,8,9,10};

    //Reading beyond bounds
    cout << "numbers[12] : " << numbers[12] << endl;

    numbers[1299999] = 1000;
    cout << "numbers[1299999] : " << numbers[1299999] << endl;//won't end(crash)

    cout << "Program ending....." << endl;

    return 0;
    
}