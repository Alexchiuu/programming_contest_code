#include <iostream> 

using namespace std;

int main(){
    
    int s, t, n, m, r;
    cin >> s >> t >> n >> m >> r;
    int a[s][t] = {},b[n][m] = {},suma {},ans1 = 0,ans2 = 1000000;
    for(int i = 0; i < s; ++ i){
        for(int j = 0; j < t; ++ j){
            cin >> a[i][j];
            suma += a[i][j];
        }
    }
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            cin >> b[i][j];
        }
    }
    
    /*
    int s = 1, t = 3, n = 1, m = 10 , r = 1;
    int a[s][t] = {{7,4,7}},b[n][m] = {{6,7,7,7,4,5,0,4,4,7}},suma {18},ans1 = 0,ans2 = 1000000;
    */
    for(int i = 0; i < (n - s + 1); ++ i){
        for(int j = 0; j < (m - t + 1); ++ j){
            int dis {};
            int sumb {};
            for(int k = i; k < (i + s); ++ k){
                for(int l = j; l < (j + t); ++ l){

                    if(dis > r){
                        break;
                    }
                    if(a[(k - i)][(l - j)] != b[k][l]){
                        dis ++;
                    }
                    sumb += b[k][l];
                }
            }
            if(dis <= r){
                ans1 ++;
                if(abs(sumb - suma) < ans2){
                    ans2 = abs(sumb - suma);
                }
            }
        }
    }
    cout << ans1 << endl;
    if(ans1 == 0){
        cout << "-1" << endl;
    }else{
        cout << ans2 << endl;
    }

    return 0;
    
}