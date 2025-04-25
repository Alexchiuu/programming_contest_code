#include <bits/stdc++.h> 

using namespace std;

struct area{
    int k;
    int l, r;
    int inside;
    int outside;
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<area> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i].l >> arr[i].r,arr[i].k = i;
    sort(arr.begin(), arr.end(), [] (area a, area b){
        return a.l < b.l;
    });
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n && arr[j].l < arr[i].r; j++){
            if(arr[j].r <= arr[i].r){
                arr[i].inside = 1;
                arr[j].outside = 1;
            }
        }
    }
    vector<pair<int,int>> ans(n);
    for(int i = 0; i < n; i++) ans[arr[i].k].first = arr[i].inside, ans[arr[i].k].second = arr[i].outside;
    for(int i = 0; i < n; i++) cout << ans[i].first << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++) cout << ans[i].second << ' ';
    cout << '\n';

    return 0;
    
}