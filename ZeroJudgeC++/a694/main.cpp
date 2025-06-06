#include <iostream> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x1, y1, x2, y2;
    while(cin >> n >> m){
        int arr[n + 1][n + 1] {};
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                cin >> arr[i][j];
                arr[i][j] += (arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]);
            }
        }
        
        for(int i = 0; i < m; i ++){
            cin >> x1 >> y1 >> x2 >> y2;
            cout << arr[x2][y2] + arr[x1 - 1][y1 - 1] - arr[x2][y1 - 1] - arr[x1 - 1][y2] << "\n";
        }
    }

    return 0;
    
}