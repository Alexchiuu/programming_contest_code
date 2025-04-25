#include <Windows.h>
#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main(){

    SetConsoleOutputCP(CP_UTF8);

    int N, rand_card, number;
    char flower;
    cin.ignore();
    cin.ignore();
    cin.ignore();
    cin.ignore();
    cin >> N;
    vector<int> deck;
    srand(time(NULL));

    for(int i = 1; i <= 52; ++ i){
        deck.push_back(i);
    }

    for(int i = 0; ; ++ i){
        rand_card = rand() % deck.size();
        flower = 'A' + deck[rand_card] / 13;
        if(deck[rand_card] % 13){
            number = (deck[rand_card] % 13);
        }else{
            number = 13;
        }

        cout << flower << number << '(';
        switch(flower){
            case 'A':
                cout << "紅心";
                break;
            case 'B':
                cout << "黑桃";
                break;
            case 'C':
                cout << "方塊";
                break;
            case 'D':
                cout << "梅花";
                break;
            default:
                break;
        }
        cout << number << ')';

        if(i < N - 1){
            cout << ", ";
        }else{
            cout << endl;
            break;
        }

    }

    
    return 0;
    
}