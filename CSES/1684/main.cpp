#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAX = 1e5 + 10;

vector<vector<int> > g(MAX * 2);
vector<int> deg(MAX * 2);
vector<int> ans(MAX,-1);
vector<bool> vis(MAX * 2);

void init(){
    for(int i = 0; i < MAX; i ++){
        vis[i] = false;
    }
}

int getind(char op){
    if(op == '+') return 0;
    else return MAX;
}

bool topo(int ind){
    //cout << "ind:" << ind << '\n';
    bool check = true;
    for(int i = 0; i < g[ind].size() && check; i ++){
        cout << "g[" << ind << "][" << i << "]:" << g[ind][i] << '\n';
        if(!vis[g[ind][i]]){
            if(g[ind][i] > MAX){
                if(vis[g[ind][i] - MAX]) check = false;
            }else{
                if(vis[g[ind][i] + MAX]) check = false;
            }
            cout << "bbb\n";
            vis[g[ind][i]] = true;
            if(g[ind][i] > MAX) ans[g[ind][i] - MAX] = 1;
            else ans[g[ind][i]] = 0;
            if(!topo(g[ind][i])){
                check = false;
                break;
            }
            cout << "ccc" << '\n';
        }
    }
    return check;
}

int main(){

    int n, m;
    cin >> n >> m;

    char op1, op2;
    int ind1, ind2;
    for(int i = 0; i < n; i++){
        cin >> op1 >> ind1 >> op2 >> ind2;
        g[getind(op1)+ind1].push_back(ind2 + MAX - getind(op2));
        deg[ind2 + MAX - getind(op2)] ++;
        g[getind(op2)+ind2].push_back(ind1 + MAX - getind(op1));
        deg[ind1 + MAX - getind(op1)] ++;
    }
    bool check = true;
    //cout << "aaa\n";
    for(int i = 1; i <= m && check; i ++){
        cout << "i:" << i << '\n';
        if(ans[i] == -1){
            if(deg[i] == 0){
                ans[i] = 0;
                check = topo(i);
            }
            if(!check) break;
            if(deg[MAX + i] == 0){
                ans[i] = 1;
                check = topo(MAX + i);
            }
        }
    }
    if(check){
        for(int i = 1; i <= m; i++){
            if(ans[i] == 1){
                cout << "+ ";
            }else{
                cout << "- ";
            }
        }
        cout << '\n';
    }

    return 0;    
}