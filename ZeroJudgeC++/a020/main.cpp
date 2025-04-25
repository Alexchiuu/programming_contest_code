#include <iostream> 

using namespace std;

int symbol(char);

int main(){

    string input;
    int sumary[11],sum=0;
    cin >> input;
    sumary[0] = symbol(input[0]) / 10;
    sumary[1] = symbol(input[0]) % 10;
    for(size_t i = 2; i < 11; i++){
        sumary[i] = input[i-1] - '0';
    }
    for(size_t i = 1; i < 10; i++){
        sumary[i] *=(10 - i);
    }
    for(auto a: sumary){
        sum += a;
    }
    if(sum % 10 == 0){
        cout << "real" << endl;
    }else {
        cout << "fake" << endl;
    }

    return 0;
    
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
            return 22;
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