#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<pair<int,int> > arr(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i].first;
        arr[i].second() = i;
    }
    sort(arr.begin(), arr.end());
    
    set<pair<int,int> > s;
    for(int i = 0; i < n; i ++){
        int k = distance(s.begin(),s.lower_bound(arr[i].first));
    }
    

    return 0;    
}