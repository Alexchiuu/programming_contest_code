#include <iostream> 

using namespace std;

int main(){

    const char * message {"Hello World!"};//point to the first character

    cout << "message : " << message << endl;
    cout << "message(derefrenced) : " << * message << endl;

    //* message = 'B'//Compiler error

    char message1[] {"Hello World!"};
    message1[0] = 'B';
    cout << "message1 : " << message1 << endl;
    
    return 0;
    
}