#include <iostream> 

using namespace std;

int main(){

    size_t input {0};
    cin >> input;

    if(0 <=input && input <= 10){
        cout << input * 6 << endl;

    }else if(10 < input && input <= 20){
        cout << 40 + input * 2 << endl;

    }else if(20 < input && input < 40){
        cout << 60 + input << endl;

    }else{
        cout << 100 << endl;
        
    }
    return 0;
    
}