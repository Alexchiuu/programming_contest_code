#include <iostream> 

using namespace std;

int linecut(int);
int surfacecut(int);

int main(){

    int n;

    while(cin >> n){
        cout << surfacecut(n) << endl;
    }
    return 0;
    
}
int linecut(int n){
    if(n == 1){
        return 2;
    }else{
        return linecut(n - 1) + n;
    }
}
int surfacecut(int n){
    if(n == 1){
        return 2;
    }else{
        return surfacecut(n - 1) + linecut(n - 1);
    }

}