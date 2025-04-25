#include <iostream>


int main(){

	int max{};
    
    int a{35};
    int b{200};
	
    std::cout << std::endl;

    if(a >  b){
        max = a;
    }else{
        max = b;
    }
    std::cout << "using regular if " << std::endl;
    std::cout << "max : " << max << std::endl;

    max = (a > b)? a : b; // Ternary operator
	
    std::cout << std::endl;
    std::cout << "using ternary operator " << std::endl;
    std::cout << "max : " << max << std::endl;
	
    //max = (a > b)? a : "HELLO";//Need to be compatable
    auto max1 = (a > b)? a : 22.5f;

    std::cout << std::endl;
    std::cout << "max1 : " << max1 << std::endl;

    return 0;
}