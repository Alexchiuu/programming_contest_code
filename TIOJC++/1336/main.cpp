#include <bits/stdc++.h> 

using namespace std;

vector<vector<int>> g(200,vector<int>(200));


void dfs(int x, int y){
    int n = g[x][y];
    g[x][y] = 0;
    if(g[x - 1][y] == n) dfs(x - 1, y);
    if(g[x - 1][y + 1] == n) dfs(x - 1, y + 1);
    if(g[x][y + 1] == n) dfs(x, y + 1);
    if(g[x + 1][y + 1] == n) dfs(x + 1, y + 1);
    if(g[x + 1][y] == n) dfs(x + 1, y);
    if(g[x + 1][y - 1] == n) dfs(x + 1, y - 1);
    if(g[x][y - 1] == n) dfs(x, y - 1);
    if(g[x - 1][y - 1] == n) dfs(x - 1, y - 1);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int W, H;
    cin >> W >> H;
    char input;
    cin.ignore();
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j ++){
            cin.get(input);
            if(input == 'W' || input == 'B') g[i][j] = 0;
            else if(input == '-') g[i][j] = 1;
            else if(input == 'G') g[i][j] = 2;
        }
        cin.ignore();
    }
    int sume = 0;
    int sumg = 0;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j ++){
            if(g[i][j] == 1){
                sume ++;
                dfs(i,j);
            }else if(g[i][j] == 2){
                sumg ++;
                dfs(i,j);
            }
        }
    }
    cout << sumg << ' ' << sume << '\n';

    return 0;
    
}