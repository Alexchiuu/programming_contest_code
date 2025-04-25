#include <iostream>

using namespace std;

int main(){

    int year;
    while(cin>>year){

        if(year%100==0){
            if(year%400==0)
                cout<<"閏年"<<endl;
            else
               cout<<"平年"<<endl;            
        }else if(year%4==0)
            cout<<"閏年"<<endl;    
        else
            cout<<"平年"<<endl;
    }

    return 0;
    
}