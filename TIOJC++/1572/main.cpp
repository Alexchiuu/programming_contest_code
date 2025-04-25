#include <bits/stdc++.h> 

using namespace std;

const int MAX = 1e6 + 10;

vector<int> G[MAX];
bool seen[MAX];
int parent[MAX];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, A, B;
    cin >> n >> m >> A >> B;
    int x, y;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1; i <= n; i ++) sort(G[i].begin(), G[i].end());
    queue<int> bfs;
    bool check = false;
    bfs.push(A);
    seen[A] = true;
    while(!bfs.empty()){
        int index = bfs.front();
        bfs.pop();
        for(auto &a: G[index]){
            if(!seen[a]){
                seen[a] = true;
                parent[a] = index;
                bfs.push(a);
                if(a == B) check = true;
            }
            if(check == true) break;
        }
        if(check == true) break;
    }
    vector<int> ans;
    ans.push_back(B);
    while(ans.back() != A){
        ans.push_back(parent[ans.back()]);
    }
    cout << ans.size() - 2 << '\n';
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i];
        if(i == 0) cout << '\n';
        else cout << '-';
    }

    return 0;
    
}