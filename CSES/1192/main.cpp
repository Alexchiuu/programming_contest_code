#include <bits/stdc++.h> 

using namespace std;

vector<vector<char>> G(1000,vector<char> (1000));
int n, m;

void dfs(int x, int y){
    G[x][y] = '#';
    if(x > 0 && G[x - 1][y] == '.') dfs(x - 1, y);
    if(x < n - 1 && G[x + 1][y] == '.') dfs(x + 1,y);
    if(y > 0 && G[x][y - 1] == '.') dfs(x, y - 1);
    if(y < m - 1 && G[x][y + 1] == '.') dfs(x,y + 1);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char input;
            cin.get(input);
            G[i][j] = input;
        }
        cin.ignore();
    }
    
    long long sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(G[i][j] == '.'){
                sum ++;
                dfs(i,j);
            }
        }
    }
    cout << sum << '\n';

    return 0;
    
}