#include <bits/stdc++.h>

const int prime = 127;
const int mod = 1e9 + 7;

using namespace std;


using namespace std;

int main(){

    string s;
    cin >> s;
    vector<int> tmp = hsh(s);
    for(auto &a: tmp) cout << a << ' ';
    cout << '\n';

    return 0;
    /*
    int q;
    cin >> q;
    while(q --){
        string T;
        cin >> T;
        vector<int> tmp = hsh(T);
        int n = tmp.size();
        int sum = 0;
        int Q;
        cin >> Q;
        string P;
        while(Q--){
            cin >> P;
            vector<int> p = hsh(P);
            int s = p.back();
            int k = P.size();
            int sum = 0;
            for(int i = 0; i + k < n; i++){
                if(tmp[i + k] - tmp[i] == s || tmp[i + k] - tmp[i] + mod == s){
                    sum ++;
                }
            }
            cout << sum << '\n';
        }
    }
    */
    
}