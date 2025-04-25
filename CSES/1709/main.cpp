#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAX = 1e5;

int g[MAX];
int ng[MAX];
bool vis[MAX];

bool dfs(int ind){
    
}

int main(){

    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j ++){
            if(s[i] == 'o'){
                g[i] = j;
                ng[j] = i;
            }
        }
    }
    

    return 0;    
}