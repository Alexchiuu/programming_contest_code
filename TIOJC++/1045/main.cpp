#include <iostream> 
#include <vector>

using namespace std;

struct z{
    
    int top;
    int bottom;
    int left;
    int right;
}

int main(){

    int n;

    while(cin >> n && n != 0){
        vector<z> zs (n);
        for(int i = 0; i < n; i++){
            cin >> zs[i].top >> zs[i].bottom >> zs[i].left >> zs[i].right;
        }
    }
    return 0;
    
}