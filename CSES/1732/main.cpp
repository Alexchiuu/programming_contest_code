#include <bits/stdc++.h> 
#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int mod = 1e9 + 7;

signed main(){

    string s;
    cin >> s;
    vector<int> arr(s.size() + 1);
    vector<int> ks(s.size() + 1);
    int k = 1;
    for(int i = 1; i <= s.size(); i ++){
        arr[i] = (s[i - 1] - 'a') * k % mod;
        arr[i] = (arr[i] + arr[i - 1]) % mod;
        ks[i] = k;
        k = k * 127 % mod;
    }

    vector<int> ans;
    for(int i = 1; i < s.size(); i ++){
        int a = (arr[i] - arr[0] + mod) % mod;
        a = a * ks[s.size() - i + 1] % mod;
        int b = (arr[s.size()] - arr[s.size() - i] + mod) % mod;
        if(a == b){
            ans.push_back(i);
        }
    }
    for(auto &au: ans){
        cout << au << ' ';
    }
    cout << '\n';


    return 0;    
}