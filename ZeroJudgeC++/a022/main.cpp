#include <iostream> 

using namespace std;

int main(){
    string input;
    cin >> input;
    bool if_no = false;
    for(int i = 0; i < (input.length() / 2); i++){
        if(input[i] != input[input.length() - 1 - i])
            if_no = true;
    }
    if(if_no ==false){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    return 0;  
}