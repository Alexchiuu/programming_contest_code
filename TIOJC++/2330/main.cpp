#include <bits/stdc++.h> 
#define int long long

using namespace std;

const int MAX = 1e5 + 10;

vector<int> x(MAX);
vector<int> y(MAX);
vector<int> dis(MAX,8e18);
vector<int> price(MAX);

bool compare(int a, int b){
    if(dis[a] < dis[b]) return true;
    if(dis[a] > dis[b]) return false;
    if(price[a] < price[b]) return true;
    if(price[a] > price[b]) return false;
    if(a < b) return true;
    return false;
};

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> index(n);
    for(int i = 0; i < n; i ++) index[i] = i;
    for(int i = 0; i < n; i ++) cin >> x[i] >> y[i] >> price[i];
    int inx, iny;
    for(int j = 0; j < m; j ++){
        cin >> inx >> iny;
        for(int i = 0; i < n; i ++){
            dis[i] = min(dis[i],(inx - x[i]) * (inx - x[i]) + (iny - y[i]) * (iny - y[i]));
        }
    }
    sort(index.begin(), index.end(), compare);

    for(int i = 0; i < n; i ++){
        cout << index[i] + 1 << '\n';
    }
    return 0;
    
}