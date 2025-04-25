#include <iostream> 

using namespace std;

int main(){

    string input;
    cin >> input;

    bool start = false;

    for(int i = input.length() - 1;i >= 0; i--){

        if(input[i] != '0')
            start = true;

        if(start == true)
            cout << input[i];
            
    }
    if(start == false){
        cout << '0';
    }
    
    cout << endl;

    return 0;
    
}