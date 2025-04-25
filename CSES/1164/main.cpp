#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;



int main(){

    fastio

    int n;
    vector<pair<int,int> > arr(n);
    vector<int> room(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(),arr.end());
    stack<pair<int,int> > s;
    for(int i = 0; i < n; i ++){
        while(!s.empty() && s.top().first < arr[i].first) s.pop();
        queue<pair<int,int> > tmp;
        int mx = 0;
        while(!s.empty() && s.top().first < arr[i].second){
            tmp.push({s.top().first,s.top().second + 1});
            mx = max(mx,s.top().second + 1);
            
        }
    }


    return 0;    
}