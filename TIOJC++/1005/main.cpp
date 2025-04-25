#include <iostream>
#include <iomanip> 
#include <math.h>
#include <algorithm>

using namespace std;
/*
bool isPrime(int a, int b){
    while(!(a == 0 || b == 0)){
        if(a > b){
            a = a % b;
        }else{
            b = b % a;
        }
        if(a == 1 || b == 1){
            return true;
        }
    }
    return false;
}
*/
int main(){

    unsigned short N;
    while(cin >> N){
        if(N == 0){
            break;
        }
        unsigned short arr[N] {};

        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        int sum {};
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                if(__gcd(arr[i],arr[j]) == 1){
                    sum ++;
                }
            }
        }

        if(sum != 0){

            double pi = sqrt(6 * (N * N - N) / (2 * sum));
            cout << fixed << setprecision(6) << pi << endl;

        }else{

            cout << "No estimate for this data set." << endl;

        }

    }

    return 0;
    
}