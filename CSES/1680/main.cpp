#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAX = 1e5 + 10;

vector<int> g[MAX];
int dis[MAX] = {};
int par[MAX] = {};
int in[MAX] = {};

int main(){

    //fastio

    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i ++){
        cin >> a >> b;
        g[a].push_back(b);
        in[b] ++;
    }

    queue<int> tp;

    in[1] = 0;
    tp.push(1);
    for(int i = 2; i <= n; i ++){
        if(in[i] == 0){
            dis[i] = -MAX;
            tp.push(i);
        }
    }
    while(!tp.empty()){
        int ind = tp.front();
        tp.pop();
        for(auto &a: g[ind]){            
            in[a] --;
            if(dis[ind] + 1 > dis[a]){
                par[a] = ind;
                dis[a] = dis[ind] + 1;
            }
            if(in[a] == 0){
                tp.push(a);
            }
        }
    }

    
    for(int i = 0; i <= n; i ++){
        cout << dis[i] << ' ';
    }
    cout << '\n';
    
    if(dis[n] <= 0){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << dis[n] + 1 << '\n';
        vector<int> ans;
        int tmp = n;
        while(tmp != 1){
            ans.push_back(tmp);
            tmp = par[tmp];
        }
        ans.push_back(1);
        for(int i = ans.size() - 1; i >= 0; i --){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;    
}