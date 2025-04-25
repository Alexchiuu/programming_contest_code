#include<iostream> 
using namespace std;
int main(){

    int var1 {5};
    cout << "var1 : " << var1 << endl;

    var1 = 6 ;//Assign
    cout << "var1 : " << var1 << endl;

    cout << "--------------" << endl;

    double var2 {5.6};
    cout << "var1 : " << var2 << endl;

    var2 = 5.7 ;//Assign
    cout << "var1 : " << var2 << endl;

    cout << "--------------" << endl;

    bool state {false};
    cout << boolalpha ;
    cout << "state : " << state << endl;

    state = true;//Assign
    cout << "state : " << state << endl;

    cout << "--------------" << endl;

    auto var3 {333u};

    var3 = -22;//Assign a negative (danger!)

    cout << "var3 : " << var3 << endl;
    return 0 ;
    
}