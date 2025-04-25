#include <iostream> 

using namespace std;

int main(){

    size_t mod30 {},mod31 {},mod32 {};

    int sum,input;
    cin >> sum;

    for(size_t i = 0; i < sum; i++){
        cin >> input;
        if(input % 3 == 0)
            mod30++;
        else if(input % 3 == 1)
            mod31++;
        else if(input % 3 == 2)
            mod32++;
    }
    cout << mod30 << ' ' << mod31 << ' ' << mod32 << endl;

    return 0;
    
}