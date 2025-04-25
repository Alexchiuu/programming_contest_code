#include <iostream> 

using namespace std;

int main(){

    int n {},m{};
    while(cin >> n >> m){
        int sum = 0, count = 0;
        for (size_t i = n; sum <= m; i++){
            sum += i;
            count++;               
        }
        if(count == 0){
            count++;
        }
        cout << count << endl;
    }
    return 0;
    
}