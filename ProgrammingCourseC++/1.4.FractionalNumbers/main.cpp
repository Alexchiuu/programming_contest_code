#include <iostream> 
#include <iomanip>

using namespace std;

int main(){

    //Declare and initialize the variables
    float number1 {1.12345678901234567890f};//Precision : 7
    double number2 {1.12345678901234567890};//Precision : 15
    long double number3 {1.12345678901234567890L};//Precision :

    //Print out the sizes
    cout<<"sizeof float : "<<sizeof(float)<<endl;
    cout<<"sizeof double : "<<sizeof(double)<<endl;
    cout<<"sizeof long double : "<<sizeof(long double)<<endl;

    //Precision
    cout<<setprecision(20);//Conntrol the precision from cout
    cout<<"number1 is : "<< number1 <<endl;
    cout<<"number2 is : "<< number2 <<endl;
    cout<<"number3 is : "<< number3 <<endl;

    //Narrowing error
    float number4 {192400023.0f};//braced initialization

    cout<<"number4 is : "<< number4 <<endl;

    cout<< "-----------------------------" <<endl;

    double number5 {192400023.0};
    double number6 {1.92400023e8};
    double number7 {1.924e8};  //omit the 0023

    double number8 {0.00000000003498};
    double number9 {3.498e-11};

    cout<<"number5 is : "<< number5 <<endl;
    cout<<"number6 is : "<< number6 <<endl;
    cout<<"number7 is : "<< number7 <<endl;
    cout<<"number8 is : "<< number8 <<endl;
    cout<<"number9 is : "<< number9 <<endl;

    cout<< "-----------------------------" <<endl;

    //Infinity and NaN
    double number10{5.6};
    double number11{};
    double number12{};

    double result { number10 / number11 }; //Infinity

    cout<< number10 << "/" << number11 << " yields " << result << endl;
    cout<< result << " + " << number10 << " yields " << result + number10 << endl;

    result = number11 / number12; //NaN(not a number)

    cout << number11 << "/" << number12 << " = "<< result << endl;
    return 0;
    
}