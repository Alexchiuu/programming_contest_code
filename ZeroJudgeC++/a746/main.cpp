#include <iostream> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while(cin >> n >> m){
        char arr[n][n] {};
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                arr[i][j] = ' ';
            }
        }
        int x1, y1, x2, y2;
        cin >> x1 >> y1;
        for(int i = 1; i < m; i++){
            cin >> x2 >> y2;
            if(x1 == x2){
                if(y1 < y2){
                    for(int j = y1 - 1; j < y2; j ++){
                        arr[x1 - 1][j] = '*';
                    }
                }else{
                    for(int j = y2 - 1; j < y1; j ++){
                        arr[x1 - 1][j] = '*';
                    }
                }
            
            }else{
                if(x1 < x2){
                    for(int j = x1 - 1; j < x2; j ++){
                        arr[j][y2 - 1] = '*';
                    }
                }else{
                    for(int j = x2 - 1; j < x1; j ++){
                        arr[j][y2 - 1] = '*';
                    }
                }
            }
            x1 = x2;
            y1 = y2;
        }
        for(int i = 0; i < n + 2; i++){
            cout << "-";
        }
        cout << "\n";
        for(int i = 0; i < n; i ++){
            cout << '|';
            for(int j = 0; j < n; j ++){
                cout << arr[i][j];
            }
            cout << '|' << "\n";
        }
        for(int i = 0; i < n + 2; i++){
            cout << "-" ;
        }
        cout << "\n";
    }

    return 0;
    
}