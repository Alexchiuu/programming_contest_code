#include <iostream> 

using namespace std;

int main(){

    int value {45};

    cout << "The value is : " << value << endl;

    cout << endl;
    value += 5;
    cout << "The value is (after +=5): " << value << endl;

    cout << endl;
    value -= 5;
    cout << "The value is (after -=5): " << value << endl;

    cout << endl;
    value *= 2;
    cout << "The value is (after *=2): " << value << endl;
    
    cout << endl;
    value /= 3;
    cout << "The value is (after /=3): " << value << endl;

    cout << endl;
    value %= 11;
    cout << "The value is (after %=11): " << value << endl;
    
    return 0;
    
}