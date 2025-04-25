#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAX = 2e5 + 10;

int len[MAX];
int nlen[MAX];
int dis[MAX];
int slen[MAX];

vector<int> g[MAX];

int DFS(int ind, int fr){
    //cout << "DFS" << ind << '\n';
    if(g[ind].size() == 1 && ind != 1){
        return 0;
    }else{
        len[ind] = 0;
        slen[ind] = 0;
        for(int i = 0; i < g[ind].size(); i ++){
            if(g[ind][i] != fr){
                int k = DFS(g[ind][i],ind) + 1;
                if(k >= len[ind]){
                    nlen[ind] = g[ind][i];
                    slen[ind] = len[ind];
                    len[ind] = k;
                }else if(k > slen[ind]){
                    slen[ind] = k;
                }
            }
        }
        //cout << ind << ":" << len[ind] << '\n';
        return len[ind];
    }
}

void DFS2(int ind, int bk, int fr){
    //cout << "DFS2:" << ind << ' ' << len[ind] << ' ' << bk << '\n';
    dis[ind] = max(len[ind],bk);
    for(int i = 0; i < g[ind].size(); i ++){
        if(g[ind][i] != fr){
            if(g[ind][i] == nlen[ind]){
                DFS2(g[ind][i], max(bk,slen[ind]) + 1, ind);
            }else{
                DFS2(g[ind][i], max(bk,len[ind]) + 1, ind);
            }
        }
    }
}

int main(){

    int n;
    cin >> n;
    int a, b;
    for(int i = 1; i < n; i ++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dis[1] = DFS(1,0);
    DFS2(1,0,0);

    for(int i = 1; i <= n; i ++) cout << dis[i] << ' ';
    cout << '\n';
    return 0;    
}