#include <iostream> 
#include "person.h"
//Variable
double weight {};

struct Point{

    double m_x;
    double m_y;

};
/*
struct Point {

    double m_x;
    double m_y;

}
*/
/*
class Person{


}//Can't declare a class that was declared in header
*/
double add(double a, double b);
int main(){

    Person p1("Jhon Snow",35);
    p1.print_info();

    double result = add(10,20);

    std::cout << "result : " << result << std::endl;
    
    return 0;
    
}
double add(double a,double b){

    return a + b;

}

