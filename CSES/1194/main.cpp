#include <bits/stdc++.h> 

using namespace std;

const int mx[4] = {1,-1,0,0};
const int my[4] = {0,0,1,-1};
int n, m;

bool isbound(int x, int y){
    return (x == 1 || y == 1 || x == n || y == m);
}

int main(){
    cin >> n >> m;
    vector<vector<char> > g(m + 2, vector<char> (n + 2,'#'));
    queue<pair<int,int> > monster;
    queue<pair<int,int> > player;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j ++){
            cin.get(g[i][j]);
            if(g[i][j] == 'M'){
                monster.push(make_pair(i,j));
                g[i][j] = '#';
            }
        }
    }
    bool check = false;
    while(check && !player.empty()){
        if(!monster.empty()){
            
        }

    }


    return 0;
    
}