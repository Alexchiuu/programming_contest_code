#include <iostream> 
#include <random>
#include <ctime>

using namespace std;

void bubblesort(int arr[],int n){
    
    
}

int main(){

    srand(time(NULL));

    int arr[50];

    for(int i = 0; i < 50; i++){
        arr[i] = rand() % 50;
        cout << arr[i] << " ";
    }
    cout << endl;

    

    return 0;
    
}