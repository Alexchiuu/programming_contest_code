#include <iostream> 
#include <math.h>
#include <algorithm>

using namespace std;

bool isprime(int);

int main(){
    int n {98};
    while(cin >> n && n != 0){
        if(isprime(n)){
            cout << 1 << " " << n << endl;
        }else if(n % 2 == 0){
            int start = n / 2;
            for(int i = start; i >= 2 ;i --){
                if(isprime(i) && isprime(n - i)){
                    cout << 2 << " " << i << " " << n - i << endl;
                    break;
                }
            }
        }else if(isprime(n-2)){
            cout << 2 << " " << 2 << " " << n - 2 << endl;
        }else{
            int start = n / 3; 
            for(int i = start; i >=2 ;i --){
                if(isprime(i)){
                    for(int j = (n - i) / 2; j >= 2 ;j --){
                        if(isprime(j) && isprime(n - i - j)){
                            int ans[3] = {j,i,n - i - j};
                            sort(ans,ans + 3);
                            for(auto a:ans){
                                cout << a << " ";
                            }
                            cout << endl;
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }

    return 0;
    
}
bool isprime(int num){

    if(num == 2 || num == 3){
        return true;
    }else if(num % 2 == 0 || num == 1){
        return false;
    }else if(num % 6 == 1 || num % 6 == 5){

        for(int i = 3; i <= sqrt(num); i += 2){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}