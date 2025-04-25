#include <iostream> 

using namespace std;

int main(){

    //int * data = new int[1000000000000000000000];//
    /*
    for(size_t i{0};i<1000000 ;++i){

        int * data =new int[10000];

    }
    */
    //exception mechanism
    /*
    for(size_t i{0};i<1000000 ;++i){
        try{
            int * data =new int[10000000000];

        }catch(exception& ex){

            cout << "Something went wrong : " << ex.what() << endl;

        }
    }
    */

    for(size_t i{0};i<1000000 ;++i){

        int * data =new(nothrow) int[1000000];

        if(data != nullptr){
            cout << "Data allocated" << endl;
        }else{
            cout << "Data allocation fails" << endl;
        }
    }

    cout << "Program ending well" << endl;

    return 0;
    
}