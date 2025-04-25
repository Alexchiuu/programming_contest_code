#include <iostream> 
#include <iomanip>

using namespace std;

int main(){
    size_t n {};
    cin >> n;
    for(int i = 0; i < n; ++ i){

        double m,p,x;
        cin >> m >> p;

        x = (p - m) / m * 100;


        
        if(x > 0){
            x += 0.00001;
        }else if (x < 0){
            x -= 0.00001;
        }
        
        cout << setw(6) << fixed << setprecision(2) << x << "% ";

        if(x >= 10 || x <= -7){
            cout << "dispose" << endl;
        }else{
            cout << "keep" << endl;
        }

    }

    return 0;
    
}