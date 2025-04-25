#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> graph;
int mn = 100000;
int n, m, k;

void update(int x, int y, int z){
    graph[x][y][z] *= -1;
    graph[x + 1][y][z] *= -1;
    graph[x - 1][y][z] *= -1;
    graph[x][y + 1][z] *= -1;
    graph[x][y - 1][z] *= -1;
    graph[x][y][z + 1] *= -1;
    graph[x][y][z - 1] *= -1;
}

void check(int level,int sum){
    for(int j = 1; j <= m; j ++){
        for(int l = 1; l <= k; l ++){
            if(graph[level - 1][j][l] == -1){
                update(level,j,l);
                sum ++;
            }
        }
    }

    if(level == n){
        for(int j = 1; j <= m; j ++){
            for(int l = 1; l <= k; l ++){
                if(graph[n][j][l] == -1){
                    return;
                }
            }
        }
        mn = min(mn,sum);
        return;
    }
    check(level + 1, sum);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int q = 0; q < t; q++){
        mn = 100000;
        int shape;
        int a, b, c;
        cin >> a >> b >> c;
        if(max(a,max(b,c)) == a){
            shape = 1;
            n = a, m = b, k = c;
        }else if(max(a,max(b,c)) == b){
            shape = 2;
            n = b, m = a, k = c;
        }else{
            shape = 3;
            n = c, m = a, k = b;
        }
        vector<vector<vector<int>>> keep(n + 2,vector<vector<int>>(m + 2,vector<int>(k + 2)));
        int input;
        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= b; j ++){
                for(int l = 1; l <= c;l ++){
                    cin >> input;
                    int getnum = 0;
                    if(input == 0){
                        getnum = -1;
                    }else{
                        getnum = 1;
                    }
                    if(shape == 1){
                        keep[i][j][l] = getnum;
                    }else if(shape == 2){
                        keep[j][i][l] = getnum;
                    }else{
                        keep[l][i][j] = getnum;
                    }
                }
            }
        }

        for(int i = 0; i < 1 <<(m * k); i ++){
            graph = keep;
            int sum = 0;
            for(int j = 1; j <= m; j ++){
                for(int l = 1; l <= k; l ++){
                    if(i & 1 <<(j + l - 2)){
                        update(1,j,l);
                        sum ++;
                    }
                }
            }
            if(n == 1){
                bool check = true;
                for(int j = 1; j <= m; j ++){
                    for(int l = 1; l <= k; l ++){
                        if(graph[n][j][l] == -1){
                            check = false;
                            break;
                        }
                    }
                }
                if(check) mn = min(mn,sum);
            }else{
                check(2,sum);
            }   
        }

        if(mn != 100000){
            cout << mn << '\n';
        }else{
            cout << "BBQQ~" << '\n';
        }
    }


    return 0;
}