#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAX = 1e5 + 10;

vector<int> g[MAX];
bool vst[MAX] = {};
bool rvst[MAX] = {};
stack<int> path;
bool chk = false;

void dfs(int n, int b){
    //cout << n << '\n';
    if(chk) return;
    //cout << n << '\n';
    path.push(n);
    if(vst[n]){
        chk = true;
        return;
    }
    vst[n] = true;
    rvst[n] = true;
    for(auto &a: g[n]){
        if(a != b) dfs(a, n);
    }
    if(chk) return;
    vst[n] = false;
    path.pop();
    return;
}

int main(){

    int n, m;
    cin >> n >> m;

    while(m --){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; i ++){
        if(!rvst[i]) dfs(i,0);
    }       

    if(chk){
        stack<int> ans;
        int k = path.top();
        ans.push(path.top());
        path.pop();
        while(path.size() > 0){
            //cout << path.size() << '\n';
            ans.push(path.top());
            if(path.top() == k) break;
            path.pop();
        }
        cout << ans.size() << '\n';
        while(ans.size() > 0){
            cout << ans.top() << ' ';
            ans.pop();
        }
    }else{
        cout << "IMPOSSIBLE\n";
    }
    return 0;    
}