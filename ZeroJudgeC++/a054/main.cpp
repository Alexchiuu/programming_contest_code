#include <iostream> 

using namespace std;

string input;
int symbol(char);
bool checking(char);

int main(){

    cin >> input;
    for(int i = 0; i <= 25; i++){
        if(checking('A' + i)){
            cout << char('A' + i);
        }
    }
    cout << endl;
    return 0;
}
bool checking(char atry){

    int sumary[11],sum=0;
    sumary[0] = symbol(atry) / 10;
    sumary[1] = symbol(atry) % 10;
    for(size_t i = 2; i < 11; i++){
        sumary[i] = input[i-2] - '0';
    }
    for(size_t i = 1; i < 10; i++){
        sumary[i] *=(10 - i);
    }
    for(auto a: sumary){
        sum += a;
    }
    if(sum % 10 == 0){
        return true;
    }else {
        return false;
    }    
}
int symbol(char symbol){
    switch(symbol){
        case 'A' :
            return 10;
        case 'B' :
            return 11;
        case 'C' :
            return 12;
        case 'D' :
            return 13;
        case 'E' :
            return 14;
        case 'F' :
            return 15;
        case 'G' :
            return 16;
        case 'H' :
            return 17;
        case 'I' :
            return 34;
        case 'J' :
            return 18;
        case 'K' :
            return 19;
        case 'L' :
            return 20;
        case 'M' :
            return 21;
        case 'N' :
            return 22;
        case 'O' :
            return 35;
        case 'P' :
            return 23;
        case 'Q' :
            return 24;
        case 'R' :
            return 25;
        case 'S' :
            return 26;
        case 'T' :
            return 27;
        case 'U' :
            return 28;
        case 'V' :
            return 29;
        case 'W' :
            return 32;
        case 'X' :
            return 30;
        case 'Y' :
            return 31;
        case 'Z' :
            return 33;
    }
}