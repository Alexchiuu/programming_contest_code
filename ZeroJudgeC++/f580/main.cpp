#include <iostream> 
#include <vector>

using namespace std;

struct dice{
    int front;
    int top;
    int bottom;
    int left;
    int right;
    int behind;
};

int main(){

    int n, m;
    cin >> n >> m;
    dice d = {4, 1, 6, 5, 2, 3};
    vector<dice> dices(n + 1, d);

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;

        if(b > 0){
            d = dices[a];
            dices[a] = dices[b];
            dices[b] = d;
        }else{
            int swap;
            if(b == -1){
                swap = dices[a].top;
                dices[a].top = dices[a].behind;
                dices[a].behind = dices[a].bottom;
                dices[a].bottom = dices[a].front;
                dices[a].front = swap;
            }else if(b == -2){
                swap = dices[a].top;
                dices[a].top = dices[a].left;
                dices[a].left = dices[a].bottom;
                dices[a].bottom = dices[a].right;
                dices[a].right = swap;
            }
        }
    } 
    for(int i = 1; i <= n; i ++){
        cout << dices[i].top << " ";
    }
    cout << endl;

    return 0;
    
}