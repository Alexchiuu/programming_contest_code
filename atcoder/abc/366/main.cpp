#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){

    int N;
    cin >> N;
    vector<vector<vector<int> > > cube(N + 1, vector<vector<int> > (N + 1, vector<int> (N + 1)));
    
    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= N; j ++){
            for(int k = 1; k <= N; k ++){
                cin >> cube[i][j][k];
                cube[i][j][k] += cube[i-1][j][k] + cube[i][j-1][k] + cube[i][j][k-1] - cube[i - 1][j - 1][k] - cube[i - 1][j][k - 1] - cube[i][j - 1][k - 1] + cube[i - 1][j - 1][k - 1];
            }
        }
    }
    /*
    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= N; j ++){
            for(int k = 1; k <= N; k ++){
                cout << cube[i][j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    */
    
    int q;
    cin >> q;
    while(q--){
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        cout << cube[rx][ry][rz] - cube[lx-1][ry][rz] - cube[rx][ly-1][rz] - cube[rx][ry][lz - 1] + cube[lx-1][ly - 1][rz] + cube[rx][ly-1][lz - 1] + cube[lx - 1][ry][lz - 1];- cube[lx-1][ly-1][lz-1];
        cout << '\n';
    }

    return 0;
}