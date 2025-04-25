#include <iostream> 

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, l, r;

    while(cin >> n >> m){

        int sum[n + 1] {};

        for(int i = 1; i <= n; i++){

            cin >> sum[i];
            sum[i] += sum[i - 1];

        }

        for(int i = 0; i < m; i++){

            cin >> l >> r;
            cout << (sum[r] - sum[l - 1]) << endl;

        }
    }
    return 0;
    
}