#include <bits/stdc++.h> 
#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int mod = 1e9 + 7;

int pw(int n, int p){
    if(p == 1){
        return n % mod;
    }
    int tmp = pw(n,p/2);
    if(p % 2 == 0){
        return tmp * tmp % mod;
    }else{
        return tmp * tmp % mod * n % mod;
    }
}

signed main(){

    string s;
    cin >> s;
    vector<int> k(s.size() + 1);
    vector<int> arr(s.size() + 1);

    int n = 1;
    for(int i = 1; i <= s.size(); i ++){
        arr[i] = (s[i - 1] - 'a') * n % mod;
        arr[i] = (arr[i - 1] + arr[i]) % mod;
        k[i] = n;
        n = (n * 127) % mod;
    }

    vector<int> ans;

    for(int i = 1; i <= s.size(); i ++){
        int tmp = pw(127,i);
        int a = (pw(tmp,(s.size() / i)) + mod - 1) % mod * arr[i] % mod;
        int b = arr[(s.size() / i) * i] * (tmp + mod - 1) % mod;
        int c = arr[s.size() - (s.size() / i) * i] * k[(s.size() / i) * i + 1] % mod;
        int d = (arr[s.size()] - arr[(s.size() / i) * i] + mod) % mod;
        if(a == b && (c == d || s.size() % i == 0)){
            ans.push_back(i);
        }
    }   
    for(auto & au: ans){
        cout << au << ' ';
    }
    cout << '\n';
    return 0;    
}