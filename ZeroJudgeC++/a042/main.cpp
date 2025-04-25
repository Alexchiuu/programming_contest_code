#include <iostream> 

using namespace std;

int main(){

    int n;

    while(cin >> n){
        int result = 2;
        for (size_t i = 1; i < n; i++){
            result += (i * 2);
        }

        cout << result << endl;
    }
    return 0;
    
}