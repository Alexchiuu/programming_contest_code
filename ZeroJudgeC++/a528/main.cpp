#include <iostream> 
#include <algorithm>

using namespace std;

int main(){

    int N{};

    while(cin >> N){
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        std::sort(arr,arr  + N);
        for(auto a:arr){
            cout << a << endl;
        }
    }

    return 0;
    
}