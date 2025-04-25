#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int q = 1; q <= T; q ++){
        char ig;
        cin >> ig >> ig;
        int n;
        cin >> n;
        bool check = true;
        vector<vector<long long> > arr(n,vector<long long> (n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j ++){
                cin >> arr[i][j];
                if(arr[i][j] < 0) check = false;
            }
        }
        if(check){
            for(int i = 0; i < n / 2 + 1; i ++){
                for(int j = 0; j < n; j ++){
                    if(arr[i][j] != arr[n - i - 1][n - j - 1]){
                        check = false;
                        break;
                    }
                }
            }
        }
        cout << "Test #" << q << ": ";
        if(check) cout << "Symmetric.\n";
        else cout << "Non-symmetric.\n";

    }

    return 0;
}