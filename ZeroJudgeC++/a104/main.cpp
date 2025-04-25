#include <iostream> 
#include <algorithm>

using namespace std;

int main(){


    size_t times;
    while(cin >> times){
        int input[times] = {};
        for(size_t i = 0; i < times; i++){
            cin >> input[i];
        }
        sort(input,input + times);
        for(size_t i = 0; i < times; i++){
            cout << input[i] << ' ';
        }
        cout << endl;
    }

    return 0;
    
}