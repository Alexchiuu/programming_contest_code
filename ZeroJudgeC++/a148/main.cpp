#include <iostream> 

using namespace std;

int main(){

    size_t n {}, score {};
    while(cin >> n){

        int if_pass = 0;
        for(size_t i = 0; i < n; i++){
            cin >> score;
            if_pass += (score - 59);
        }

        if(if_pass > 0){
            cout << "no" << endl;
        }else{
            cout << "yes" << endl;
        }

    }

    return 0;
    
}