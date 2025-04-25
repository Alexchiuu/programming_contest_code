#include <iostream> 

using namespace std;

int f(int n){

    if(n == 0){

        return -1;

    }else if(n == 1){

        return 0;

    }
    
    return (f(n-1) + 2) % n;

}

int main(){

    int n {};
    cin >> n;

    cout << f(n) + 1 << endl;
    return 0;
    
}