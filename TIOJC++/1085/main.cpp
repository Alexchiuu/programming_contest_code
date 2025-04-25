#include <bits/stdc++.h> 

using namespace std;

const int bx[6] = {0,0,0,0,1,-1};
const int by[6] = {0,0,1,-1,0,0};
const int bz[6] = {1,-1,0,0,0,0};

struct node{
    int x;
    int y;
    int z;
};

vector<vector<vector<int>>> g(52,vector<vector<int>> (52,vector<int> (52,1)));
vector<vector<vector<node>>> parent(52,vector<vector<node>> (52,vector<node> (52)));

int main(){

    int x, y, z;
    cin >> x >> y >> z;
    for(int i = 1; i <= z; i ++){
        for(int j = 1; j <= y; j ++){
            for(int k = 1; k <= x; k++){
                cin >> g[k][j][i];
            }
        }
    }

    queue<node> bfs;
    bfs.push({1,1,1});
    if(g[1][1][1] == 1 || g[x][y][z] == 1) bfs.pop();
    g[1][1][1] = 1;
    bool check = false;
    if(x == 1 && y == 1 && z == 1) check = true;
    while(!bfs.empty()){
        node index = bfs.front();
        bfs.pop();
        for(int i = 0; i < 6; i++){
            if(g[index.x + bx[i]][index.y + by[i]][index.z + bz[i]] == 0){
                g[index.x + bx[i]][index.y + by[i]][index.z + bz[i]] = 1;
                parent[index.x + bx[i]][index.y + by[i]][index.z + bz[i]] = index;
                bfs.push({index.x + bx[i],index.y + by[i],index.z + bz[i]});
                if(index.x + bx[i] == x && index.y + by[i] == y && index.z + bz[i] == z){
                    check = true;
                    break;
                }
            }
        }
    }
    if(check){
        vector<node> ans;
        node index = {x,y,z};
        ans.push_back({x,y,z});
        while(index.x != 1 || index.y != 1 || index.z != 1){
            index = parent[index.x][index.y][index.z];
            ans.push_back(index);
        }
        for(int i = ans.size() - 1; i >= 0; i--){
            cout << "(" << ans[i].x << ',' << ans[i].y << ',' << ans[i].z << ')';
            if(i == 0) cout << '\n';
            else cout << "->";
        }
    }else{
        cout << "no route" << '\n';
    }


    return 0;
    
}