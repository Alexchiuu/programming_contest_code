#include <iostream> 

using namespace std;

int max(int a, int b); //Function declaration, prototype
                       //Singnature doesn't include return type
int min(int a, int b);

int inc_mult(int , int );//Functions Declarations don't need a variable name
int main(){

    int x {5};
    int y {12};

    int result = inc_mult(x,y);
    cout << "result : " << result << endl;

    return 0;
    
}

int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int min(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

int inc_mult(int a, int b){
    return ((++a) * (++b));
}
