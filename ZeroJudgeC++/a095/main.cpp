#include <iostream> 

using namespace std;

int main(){
    int N {}, M {};
    while(cin >> N >> M){
        if(N > M >=1){
            cout << M + 1 << endl;
        }else{
            cout << M << endl;
        }
    }

    return 0;
    
}