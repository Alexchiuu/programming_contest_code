#include <iostream> 
#include <algorithm>
#include <cstring>

using namespace std;

bool checking(char );
string capitalizeString(string s);
char checked[128] ={};

void array_set_up(){

    for(int i = 0; i < 128; i++){

        checked[i] = ' ';
    }
}

int main(){
    string input {};
    bool check = true;
    int chance = 0,count = 0;
    char inpchr = {};
    while(cin >> input){


        input = capitalizeString(input);
        check = true;
        chance = 0;
        count = 0;
        inpchr = {};
        int notalpha = 0;
        for(int i = 0; i < input.length(); i++){
            if( 'A' <= input[i] && input[i] <= 'Z'){

            }else{
                notalpha ++;
            }
        }
        array_set_up();

        if((input.length() - notalpha) % 2 != 0)
            chance++;

        for(int i = 0; i < input.length(); i++){
            if( 'A' <= input[i] && input[i] <= 'Z'){
                inpchr = input[i];
                if(checking(inpchr)){
                    checked[i] = inpchr;
                    for(int j = 0; j < input.length(); j++){

                        if(inpchr == input[j]){
                            count++;
                        }
                    }
                    if(count % 2 != 0){

                        if(chance == 1){
                            chance--;
                        }else{
                            check = false;
                            break;
                        }
                    }
                }
                count = 0;
            }
            
        }

        if(check)
            cout << "yes !" << endl;
        else
            cout << "no..." << endl;

    }
    return 0;
    
}
string capitalizeString(string s)
{
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return toupper(c); });
    return s;
}
bool checking(char in){

    for(int i = 0; i < 128; i++){
        if(checked[i] == in){
            return false;
        }
    }
    return true;

}
