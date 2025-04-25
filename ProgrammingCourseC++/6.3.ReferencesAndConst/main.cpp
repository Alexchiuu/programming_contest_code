#include <iostream> 

using namespace std;

int main(){

    //Non const reference
	std::cout << std::endl;
	std::cout << "Non const reference : " << std::endl;
	int age {27};
	int& ref_age{age};
	
	std::cout << "age : " << age << std::endl;
	std::cout << "ref_age : " << ref_age << std::endl;
	
	
	//Can modify original variable through reference
	std::cout << std::endl;
	std::cout << "Modify original variable through reference : " << std::endl;
	
	ref_age++; //Mofify through reference
	
	std::cout << "age : " << age << std::endl;
	std::cout << "ref_age : " << ref_age << std::endl;

    //Const reference
	std::cout << std::endl;
	std::cout << "Non const reference : " << std::endl;
	int age1 {27};
	const int& ref_age1{age1};
	
	std::cout << "age : " << age1 << std::endl;
	std::cout << "ref_age : " << ref_age1 << std::endl;
	
	
	//Can modify original variable through reference
	std::cout << std::endl;
	std::cout << "Modify original variable through reference : " << std::endl;
	
	//ref_age1++; //Can't modify through reference
	
	std::cout << "age : " << age1 << std::endl;
	std::cout << "ref_age : " << ref_age1 << std::endl;
    

    //Simulating reference behavior with pointers
    //const int * const p_age {&age};//An address can't be a const
    //*p_age = 45;
    return 0;
    
}