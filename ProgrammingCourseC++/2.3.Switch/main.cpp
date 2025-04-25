#include <iostream> 
#include <string>

// Tools
const int Pen{ 10 };
const int Marker{ 20 };
const int Eraser{ 30 };
const int Rectangle{ 40 };
const int Circle{ 50 };
const int Ellipse{ 60 };

using namespace std;

int main(){

    int tool {Ellipse};

    switch (tool)
    {
        case Pen : {
             std::cout << "Active tool is Pen" << std::endl;
        }
        break;

        case Marker : {
             std::cout << "Active tool is Marker" << std::endl;
        }
        break;

        case Eraser : {
             std::cout << "Active tool is Eraser" << std::endl;
        }
        break;

        case Rectangle : {
             std::cout << "Active tool is Rectangle" << std::endl;
        }
        break;

        case Circle : {
             std::cout << "Active tool is Circle" << std::endl;
        }
        break;

        case Ellipse : {
             std::cout << "Active tool is Ellipse" << std::endl;
        }
        break;
    
        default: {
            std::cout << "No match found" << std::endl;
        }
        break;
    }

    std::cout << "Moving on" << std::endl;


    /*
    // Condition can only be integer of enum (We'll learn about enums later in the course)
    std::string name {"John"};
    switch (name) // Compiler error!
    {
    
    }
    */

    return 0;
    
}