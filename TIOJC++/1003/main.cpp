#include <iostream> 

using namespace std;

int f(int n){
    if(n > 0){
        return f(n - 1) + n;
    }
    return 1; 
}

int main(){

    int n;
    cin >> n;
    cout << f(n) << endl; 
    return 0;
    
}