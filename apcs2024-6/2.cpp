#include<bits/stdc++.h>

using namespace std;

int g[30][30] = {};
bool v[30][30] = {};

int x;

void dfs(int l,int cx,int cy){
    if(l == 0) return;
    g[cx][cy] += x;
    v[cx][cy] = false;
    if(v[cx + 1][cy]) dfs(l-1,cx+1,cy);
    if(v[cx - 1][cy]) dfs(l-1,cx-1,cy);
    if(v[cx][cy + 1]) dfs(l-1,cx,cy+1);
    if(v[cx][cy - 1]) dfs(l-1,cx,cy-1);
    return;
}

int main(){

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int h, w, n;
    cin >> h >> w >> n;

    while(n--){
        for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++){
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
        for(int i = 1; i <= h; i ++){
            for(int j = 1; j <= w; j ++){
                v[i][j] = true;
            }
        }
        int r, c, t;
        cin >> r >> c >> t >> x;;
        dfs(t + 1,r + 1,c + 1);
    }

    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++){
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;

}