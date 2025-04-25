#include <iostream> 
#include <iomanip>

using namespace std;

int main(){

    int a1, b1, c1, a2, b2, c2;
    double dx, dy, delta;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    dx = c1 * b2 - c2 * b1;
    dy = a1 * c2 - a2 * c1;
    delta = a1 * b2 - a2 * b1;
    if(delta == 0){
        if(dx == 0 && dy == 0){
            cout << "Too many" << endl;
        }else {
            cout << "No answer" << endl;
        }

    }else{
        cout << "x=" << fixed << setprecision(2) << (dx / delta) << endl;
        cout << "y=" << fixed << setprecision(2) << (dy / delta) << endl;
    }
    

    return 0;
    
}