#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    srand(time(NULL));
    int m, n;
    cin >> m >> n;
    int A[m][n] {};

    cout << "A=" << endl;

    for(int i = 0; i < m; ++ i){
        for(int j = 0; j < n;  ++ j){
            A[i][j] = rand() % 10;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "B=" << endl;

    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            cout << A[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
    
}