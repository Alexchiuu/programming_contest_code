#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 10;

int dsu[MAX];

void init(int n){
    for(int i = 0; i <= n; i ++){
        dsu[i] = i;
    }
}

int query(int ind){
    if(dsu[ind] == ind) return ind;
    int tmp = query(dsu[ind]);
    dsu[ind] = tmp;
    return tmp;
}

void onion(int a, int b){
    dsu[query(a)] = query(b);
}

struct edge{
    int a, b, d;
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while(cin >> n >> m){
        init(n);
        vector<edge> edges(m);
        for(int i = 0; i < m; i++){
            cin >> edges[i].a >> edges[i].b >> edges[i].d;
        }
        sort(edges.begin(),edges.end(),[] (edge j, edge k){
            return j.d < k.d;
        });
        long long ans = 0;
        int sum = 0;
        for(int i = 0; i < m && sum != n - 1;i ++){
            if(query(edges[i].a) != query(edges[i].b)){
                ans += edges[i].d;
                sum ++;
                onion(edges[i].a,edges[i].b);
            }
        }
        if(sum == n - 1) cout << ans << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}