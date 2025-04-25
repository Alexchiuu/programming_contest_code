#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

void f(long long int,long long int,int);

int main(){

    long long int n = 2;
    f(n, 0, 0);
    
    return 0;
}

void f(long long int n,long long int a,int level){
    if(level == 50){
        return;
    }
    int i;
    for(i = 0; i < 10; i++){
        if((a*10+i)*i > n){
            i--;
            break;
        }else if((a*10+i)*i == n){
            return;
        }
    }
    cout << i << endl;
    level++;
    n = (n - (a*10+i)*i) * 100;
    a = a * 10 + 2 * i;
    f(n, a, level);
    return;
}