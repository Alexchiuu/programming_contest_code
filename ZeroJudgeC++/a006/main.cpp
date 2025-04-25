#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int a,b,c;
    cin>>a>>b>>c;

    int S=(int)sqrt(b*b-4*a*c);
    if(S>0){
        if((S-b)/(2*a)>(-S-b)/(2*a))
            cout<<"Two different roots x1="<<(S-b)/(2*a) <<" , x2="<<(-S-b)/(2*a);
        else
            cout<<"Two different roots x1="<<(-S-b)/(2*a) <<" , x2="<<(S-b)/(2*a);
    }else if(S==0)
        cout<<"Two same roots x="<<(S-b)/(2*a);
    else
        cout<<"No real root";

    return 0;
    
}