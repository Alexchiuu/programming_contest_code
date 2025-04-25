#include <iostream> 

using namespace std;

int main(){

    bool red_light {true};
    bool green_light {!red_light};

    if(red_light == true){
        cout << "Stop!" << endl;
    }else{
        cout << "Go through!" << endl;
    }

    if(green_light){
        cout << "The light is green" << endl;
    }else{
        cout << "The light is not green" << endl;
    }

    //size of
    cout << "sizeof bool : " << sizeof(bool) << " bytes " << endl;

    //Printing bool
    cout << endl;
    cout << "redlight : " << red_light << endl;
    cout << "greenlight : " << green_light << endl;

    cout << boolalpha; //To print bool in words
    cout << "redlight : " << red_light << endl;
    cout << "greenlight : " << green_light << endl;
    return 0;
    
}