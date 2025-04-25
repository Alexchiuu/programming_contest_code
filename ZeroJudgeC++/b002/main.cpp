#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> p;

void click(int x, int y){
    p[x][y] *= -1;
    if(x > 0) p[x - 1][y] *= -1;
    if(x < 9) p[x + 1][y] *= -1;
    if(y > 0) p[x][y - 1] *= -1;
    if(y < 9) p[x][y + 1] *= -1;
}

int brute(int level, int sum){
    if(level == 9){
        for(int i = 0; i < 10; i++){
            if(p[level - 1][i] == 1){
                click(level,i);
                sum ++;
            }
            if(i > 0 && p[9][i - 1] == 1) return 10000;
        }
        if(p[9][9] == 1) return 10000;
        return sum;
    }else{
        for(int i = 0; i < 10; i++){
            if(p[level - 1][i] == 1){
                click(level,i);
                sum ++;
            }
        }
        return brute(level + 1,sum);
    }
    return 0;
}

int main(){

    vector<vector<int>> keep(10,vector<int> (10));

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    char input;
    cin.ignore();
    for(int k = 0; k < n; k ++){

        cin.ignore();
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cin.get(input);
                if(input == 'O'){
                    keep[i][j] = 1;
                }else{
                    keep[i][j] = -1;
                }
            }
            cin.ignore();
        }
        int mn = 10000;
        
        for(int i = 0; i < 1024; i++){
            p = keep;
            int sum = 0;
            for(int j = 1,pos = 0; pos < 10; pos ++, j <<= 1 ){
                if(i & j) click(0,pos),sum ++;
            }
            mn = min(mn,brute(1,sum));
        }
        cout << mn << '\n';
    }

    return 0;
}