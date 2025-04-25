#include <iostream> 

using namespace std;

int main(){

    string input;
    cin >> input;
    for(int i = 0; i < 6; i++){
        cout << abs(input[i] - input[i + 1]);
    }
    cout << endl;

    return 0;
    
}