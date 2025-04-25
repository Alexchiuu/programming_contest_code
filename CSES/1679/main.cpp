#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAX = 1e5 + 10;

vector<int> g[MAX];
int in[MAX] = {};
bool vis[MAX] = {};

int main(){

    fastio

    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    bool flag = true;
    for(int i = 1; i <= n; i ++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(q.size() > 0){
        int tmp = q.front();
        q.pop();
        ans.push_back(tmp);
        for(auto &a: g[tmp]){
            in[a] --;
            if(in[a] == 0){
                q.push(a);
            }
        }
    }
    if(ans.size() < n){
        cout << "IMPOSSIBLE\n";
    }else{
        for(auto &a: ans){
            cout << a << ' ';
        }
        cout << '\n';
    }


    return 0;    
}