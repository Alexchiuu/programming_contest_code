#include <iostream> 
#include <stdio.h>
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n {0};
    int password[4] {};
    int guess[4] {};
    while(cin >> password[0] >> password[1] >> password[2] >>password[3]){
        
        cin >> n;
        
        for(size_t i = 0; i < n; i ++){
            
            int a = 0, b = 0;
            cin >> guess[0] >> guess[1] >> guess[2] >> guess[3];
            bool checkedpas[4] = {false,false,false,false};
            bool checkedgue[4] = {false,false,false,false};
            for(int i = 0; i < 4; i ++){
                
                if(password[i] == guess[i]){
                    a++;
                    checkedpas[i] = true;
                    checkedgue[i] = true;
                }
            }
            for(int i = 0; i < 4; i ++){

                if(!checkedgue[i]){

                    for(int j = 0; j < 4; j ++){

                        if(!checkedpas[j] && password[j] == guess[i]){

                            b++;
                            checkedpas[j] = true;
                            break;                          
                        }                       
                
                    }
                    
                }                       
                
            }
            printf("%dA%dB\n",a,b);
        }
    }
    return 0;
    
}
