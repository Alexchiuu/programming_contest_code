#include <iostream> 

using namespace std;

int main(){

    bool a {true};
    bool b {false};
    bool c {true};

    cout << boolalpha;
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
    cout << "c : " << c << endl;

    cout << endl;
    cout << "Basic AND operations" << endl;
    cout << " a && b : " << (a && b) << endl;
    cout << " a && c : " << (a && c) << endl;
    cout << " a && b && c : " << (a && b && c) << endl;

    cout << endl;
    cout << "Basic OR operations" << endl;
    cout << " a || b : " << (a || b) << endl;
    cout << " a || c : " << (a || c) << endl;
    cout << " a || b || c : " << (a || b || c) << endl;

    cout << endl;
    cout << "!a : " << !a << endl;
    cout << "!b : " << !b << endl;
    cout << "!c : " << !c << endl;

    //Combinations
    cout << endl;
    cout << "Combinations logical operrators" << endl;
    cout << "!(a && b) || c : " << (!(a && b) || c) << endl;

    int d{45};
    int e{20};
    int f{11};

    cout << endl;
    cout << "Relationals and logic operations on intergers" << endl;
    std::cout << "(d > e) && (d > f) : " << ((d > e) && (d > f)) << std::endl; // true
	std::cout << "(d==e) || (e <= f ) : " << ((d==e) || (e <= f ) ) << std::endl;
	std::cout << "(d < e) || (d > f) : " << ((d < e) || (d > f)) << std::endl;
	std::cout << "(f > e) || (d < f) : " << ((f > e) || (d < f)) << std::endl;
	std::cout << "(d > f) && (f <= d) : " << ((d > f) && (f <= d)) << std::endl;
	std::cout << "(d > e) && (d <= f) : " << ((d > e) && (d <= f)) << std::endl;
	std::cout << "(! a) && (d == e) : " << ((! a) && (d == e)) << std::endl;
	std::cout << "(! a) && (d == e) : " << ((! a) && (d == e)) << std::endl;

    return 0;
    
}