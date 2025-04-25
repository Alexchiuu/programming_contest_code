#include <bits/stdc++.h> 
#define ll long long

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> movies(n);
    for(int i = 0; i < n; i++) cin >> movies[i].first >> movies[i].second;
    multiset<int,greater<int>> member;
    for(int i = 0; i < k; i++) member.insert(0);
    sort(movies.begin(),movies.end(), [] (pair<int,int> a, pair<int,int> b){ return a.second < b.second;});
    ll sum = 0;
    for(int i = 0; i < n; i++){
        multiset<int>::iterator it = member.lower_bound(movies[i].first);
        if(it != member.end()){
            member.erase(it);
            member.insert(movies[i].second);
            sum ++;
        }
    }
    cout << sum << '\n';
    return 0;
    
}