#include <iostream>
using namespace std;

/*int prime(int n){
    int prime,k=0;
    float j=2;
    while(true){
        for(float i=1;i<j;i++){
            if(j/(j-i)==(int)(j/(j-i))&&j-i!=1){
                break;
            }else if(j-i==1){
                prime=(int)j;
                k++;
                break;
            }
        }
        if(k==n)
            break;
        j++;
    }
    return prime;
}
*/
int main(){

    int x,i=2,sqre=1,n=0;
    cin>>x;

    while(x>=i){
        if(x%i==0){
            if(n>0)
                cout<<" * ";
            cout<<i;
            x/=i;
            if(x%i==0){
                cout<<'^';
                while(x%i==0){
                    x/=i;
                    sqre++;
                }
                cout<<sqre;
                sqre=1;
            }
            n++;
        }
        i++;
    }
    return 0;
    
}