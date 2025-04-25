#include <bits/stdc++.h> 

using namespace std;

const int MAX = 2e5 + 10;
const int mod = 1e9 + 7;

int n;
int BIT[MAX];

void update(int ind,int x){
    while(ind <= n){
        BIT[ind] += x;
        BIT[ind] %= mod;
        ind += (ind & -ind);
    }
}

int query(int ind){
    int ans = 0;
    while(ind > 0){
        ans += BIT[ind];
        ans %= mod;
        ind -= (ind & -ind);
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;
    vector<int> ori(m);//lisan
    for(int i = 0; i < m; i++){
        cin >> ori[i];
    }
    vector<int> arr = ori;
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    n = arr.size();
    for(int i = 0; i < m; i++){
        int ind = lower_bound(arr.begin(),arr.end(),ori[i]) - arr.begin();
        update(ind + 1,query(ind) + 1);
    }
    cout << query(n) << '\n';

    return 0;
    
}