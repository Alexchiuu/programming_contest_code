#include <iostream> 

using namespace std;

int main(){

    int value {5};

    value = value + 1;
    cout << "The value is : " << value << endl;

    value = 5;
    value = value - 1;
    cout << "The value is : " << value << endl;

    cout << "=======Postfix increment and decrement======" << endl;

    value = 5;

    cout << "THe value is (incrementing): " << value++ << endl;
    cout << "THe value is : " << value << endl;

    value = 5;

    cout << "THe value is (decrementing): " << value-- << endl;
    cout << "THe value is : " << value << endl;

    cout << "=======Prefix increment and decrement======" << endl;

    value = 5;
    ++value;
    cout << "THe value is : " << value << endl;

    value = 5 ;
    cout << "THe value is (prefix++): " << value << endl;

    value = 5;
    --value;
    cout << "THe value is : " << value << endl;

    value = 5 ;
    cout << "THe value is (prefix--): " << --value << endl;

    return 0;
    
}