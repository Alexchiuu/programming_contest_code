#include <iostream> 

using namespace std;

const int paper {5};
const int scissors {2};
const int stone {0};

int main(){
    
    int F, N;
    cin >> F >> N;
    int lr = F,llr = F;
    int b[N] = {F},s[N] = {};
    for(int i = 0; i < N; ++ i){
        cin >> s[i];
    }
    
    /*
    int lr,llr;
    int N = 6,b[6] = {5,0,0,0,0,0},s[6] = {5,5,2,2,0,0};
    */
    for(int i = 0; i < N; ++ i){
        if(i == 0){
        }else if(i == 1){
            b[i] = lr;
        }else if(lr == llr){
            if(lr == paper){
                b[i] = scissors;
            }else if(lr == scissors){
                b[i] = stone;
            }else{
                b[i] = paper;
            }
        }else{
            b[i] = lr;
        }

        if(b[i] == s[i]){
            llr = lr;
            lr = s[i]; 
            cout << b[i] << " ";
        }else if(b[i] == paper){
            if(s[i] == scissors){
                cout << b[i] << " : Lost at round " << ++ i;
                break;
            }else{
                cout << b[i] << " : Won at round " << ++ i;
                break;
            }
        }else if(b[i] == scissors){
            if(s[i] == stone){
                cout << b[i] << " : Lost at round " << ++ i;
                break;
            }else{
                cout << b[i] << " : Won at round " << ++ i;
                break;
            }
        }else{
            if(s[i] == paper){
                cout << b[i] << " : Lost at round " << ++ i;
                break;
            }else{
                cout << b[i] << " : Won at round " << ++ i;
                break;
            }
        }
        if(i + 1 == N){
            cout << ": Drew at round " << N;
            break;
        }
    }

    return 0;
    
}