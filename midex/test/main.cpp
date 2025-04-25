#include <iostream> 

using namespace std;

struct point {
    int x;
    int y;
};
void print (struct point arr[]){
    for(int i = 0; i < 2; i++){
        cout << arr[i].x << arr[i].y << endl;
    }
}
int main(){

    struct point arr[2] = {{1, 2}, {3, 4}};
    print(arr);
    return 0;
}