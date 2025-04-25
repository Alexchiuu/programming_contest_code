#include <bits/stdc++.h> 
#define int long long

using namespace std;

const int MAX = 2e5 + 10;

vector<int> w;
vector<int> w2;
int n, k;

int ask(int mid){
    int sum = 0;
    int l = n - (lower_bound(w.begin(),w.end(),mid) - w.begin());
    for(int i = 0;i < n; i ++){
        int k = n - (lower_bound(w.begin(),w.end(),mid - w[i]) - w.begin());
        cout << mid - w[i] << " : " << k << '\n';
        sum += k;
    }
    sum = sum + l;
    return sum;
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int input;
    for(int i = 0; i < n; i ++){
        cin >> input;
        w.push_back(input);
        w2.push_back(input * 2);
    }
    sort(w.begin(),w.end());

    cout << w[0] << ' ' << w.back() << '\n';
    for(int i = 2*w[0]; i <= 2 * w.back(); i ++) cout << ask(i) << '\n';
    return 0;
    
}