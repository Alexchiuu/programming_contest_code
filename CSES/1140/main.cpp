#include <bits/stdc++.h> 

using namespace std;

struct project{
    pair<int,int> line;
    int p;
};

bool comp(project &a, project &b){
    return a.line < b.line;
}

int main(){

    int n;
    cin >> n;
    vector<project> v(n);
    for(int i = 1; i <= n; i++){
        cin >> v[i].line.first >> v[i].line.second >> v[i].p;
    }
    sort(v.begin(),v.end(),comp);
    vector<pair<int,int> > dp(n + 2,{0,0});
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(v[i].line.first > v[dp[i - 1].first].line.second){
            dp[i] = {dp[i - 1].first,;
        }
        ans = max(ans,dp[i]);
    }
    cout << ans << '\n';
    return 0;
    
}