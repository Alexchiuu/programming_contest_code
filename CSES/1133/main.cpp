#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAX = 2e5 + 10;


vector<int> g[MAX];
vector<pair<int,int> > G[MAX];
vector<pair<int,int> > len(MAX);

pair<int,int> DFS(int ind, int fr){
    if(ind != 1 && g[ind].size() == 1){
        len[ind] = {0,0};
        return {0,0};
    }else{
        pair<int,int> sum = {0,0};
        for(int i = 0; i < g[ind].size(); i ++){
            if(g[ind][i] != fr){
                sum += DFS(g[ind][i])
            }
        }
    }
}


int main(){

    int n;
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i ++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    

    return 0;    
}