#include <iostream> 

using namespace std;

int main(){

    unsigned int a {},times {};
    long int b {}, c {};
    cin >> times;
    for(size_t i = 0;i < times; i++){
        cin >> a >> b >> c;
        switch (a){
            case 1:
                cout << b + c << endl;
                break;
            case 2:
                cout << b - c << endl;
                break;
            case 3:
                cout << b * c << endl;
                break;
            case 4:
                cout << b / c << endl;
                break;
        }
    }
    return 0;
    
}