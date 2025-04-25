#include <bits/stdc++.h> 

using namespace std;

int main(){

    int max = 1;
    int rep = 1;
    char last = ' ',now;
    string input;
    cin >> input;
    for(size_t i = 0; i < input.length(); i ++){
        now = input[i];
        if(last == now){
            rep ++;
            if(rep > max){
                max = rep;
            }
        }else{
            rep = 1;
        }
        last = now;
    }

    cout << max << endl;

    return 0;
    
}