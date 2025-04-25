#include <bits/stdc++.h>
#define int long long

using namespace std;

string getstr(int n){
    string ret;
    while(n){
        if(n % 26 == 0){
            n -= 26;
            ret.push_back('Z');
        }else{
            ret.push_back('A' + (n % 26) - 1);
        }
        n /= 26;
    }
    string ans;
    for(int i = ret.size() - 1; i >= 0; i--) ans.push_back(ret[i]);
    return ans;
}

int getnum(string &a){
    int p = 1;
    int ret = 0;
    for(int i = a.size() - 1; i >= 0; i --){
        ret += (a[i] - 'A' + 1) * p;
        p *= 26;
    }
    return ret;
}

signed main(){

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;
    string input;
    stringstream ss;
    while(n --){
        cin >> input;
        if(isalpha(input[0])){
            cout << getnum(input) << '\n';
        }else{
            ss << input;
            int k;
            ss >> k;
            cout << getstr(k) << '\n';
            ss.clear();
        }
    }

    return 0;
}