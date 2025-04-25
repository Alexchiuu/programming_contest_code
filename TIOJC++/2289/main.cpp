#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<pair<int,int> > arr(q);
    for(int i = 0; i < q; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(),arr.end());
    if(arr.size() == 0) cout << 0 << '\n';
    else{
        int sum = 1;
        int mx = arr[0].second;
        for(int i = 1; i < q; i++){
            if(arr[i].first > mx){
                mx = arr[i].second;
                sum ++;
            }else{
                mx = min(arr[i].second,mx);
            }
        }
        cout << sum << '\n';
    }
    return 0;
    
}