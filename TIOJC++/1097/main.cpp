#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, w;
    while(cin >> l >> w && !(l == 0 && w == 0)){
        if(l == 0 || w == 0){
            cout << 0 << '\n';
            continue;
        }
        vector<vector<short>> g(l + 1,vector<short> (w));
        int input;
        for(int i = 1; i <= l; i ++){
            for(int j = 0; j < w; j ++){
                cin >> input;
                if(input == 2){
                    g[i][j] = 0;
                }else{
                    g[i][j] = g[i - 1][j] + 1;
                }
            }
        }
        stack<pair<int,int> > lines;
        int mx = 0;
        for(int i = 1; i <= l; i++){
            for(int j = 0; j < w; j++){
                int save = j;
                while(!lines.empty() && lines.top().first > g[i][j]){
                    mx = max(mx,min(lines.top().first,j - lines.top().second));
                    save = lines.top().second;
                    lines.pop();
                }
                lines.push({g[i][j],save});
            }
            while(!lines.empty()){
                mx = max(mx,min(lines.top().first,w - lines.top().second));
                lines.pop();
            }
        }
        cout << mx*mx << '\n';
    }
    return 0;
    
}