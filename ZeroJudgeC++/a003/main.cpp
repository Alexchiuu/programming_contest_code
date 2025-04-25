#include <iostream>

using namespace std;

int main(){

    int M,D,S;
    cin>>M>>D;
    S=(M*2+D)%3;
    switch(S){
        case 0:
            cout<<"´¶³q";
            break;
        case 1:
            cout<<"¦N";
            break;
        case 2:
            cout<<"¤j¦N";
            break;
    }
    return 0;
    
}