#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int input {};

    while(cin >> input && input != 0){

        int count = 0;
        
        while (input){
            if(input % 2 == 1){
                count ++;
                input /= 2;
            }else{
                break;
            }
        }
        cout << count << endl;
    }
    return 0;   
}