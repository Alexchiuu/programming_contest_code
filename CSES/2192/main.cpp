#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

using namespace std;

struct pt{
    int x, y;
    pt operator+ (pt vt){
        return{x + vt.x, y + vt.y};
    }
    pt operator- (pt vt){
        return{x - vt.x, y - vt.y};
    }
    int operator^ (pt vt){
        return x * vt.y - y * vt.x;
    }
    int operator* (pt vt){
        return x * vt.x + y * vt.y;
    }
};
int ori(pt a, pt b, pt p){
        if(((a - p) ^ (b - p)) == 0) return 0;
        return (((a - p) ^ (b - p)) > 0)?1:-1;
}

signed main(){

    int n, m;
    cin >> n >> m;
    pt a, b;
    vector<pt> g(n);
    for(int i = 0; i < n; i++){
        cin >> g[i].x >> g[i].y;
    }
    for(int i = 0; i < m; i ++){
        cin >> a.x >> a.y;
        b = {1000000007,a.y + 1};
        int sum = 0;
        for(int j = 0; j < n - 1; j ++){
            //cout << ori(g[j],g[j + 1],a) << '\n';
            //cout << ori(g[j],g[j + 1],b) << '\n';
            //cout << ori(a,b,g[j]) << '\n';
            //cout << ori(a,b,g[j + 1]) << '\n';
            if(ori(g[j],g[j + 1],a) * ori(g[j],g[j + 1],b) < 0 && ori(a,b,g[j]) * ori(a,b,g[j + 1]) < 0) sum ++;
            if(ori(g[j],g[j + 1],a) == 0 && (g[j] - a) * (g[j + 1] - a) <= 0){
                sum = -1;
                break;
            }
            //cout << "sum:" << sum << '\n';
        }
        if(ori(g[n - 1],g[0],a) * ori(g[n - 1],g[0],b) < 0 && ori(a,b,g[n - 1]) * ori(a,b,g[0]) < 0 && sum != -1) sum ++;
        if(ori(g[n - 1],g[0],a) == 0 && (g[n - 1] - a) * (g[0] - a) <= 0) sum = -1;
        
        if(sum == -1) cout << "BOUNDARY\n";
        else if(sum % 2 == 1) cout << "INSIDE\n";
        else if(sum % 2 == 0) cout << "OUTSIDE\n";
    }
    

    return 0;    
}