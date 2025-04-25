#include <bits/stdc++.h>

using namespace std;

vector<bool> isprime(3000,1);

void init(){
    isprime[0] = false;
    isprime[1] = false;
    for(int i = 2; i < 3000; i ++){
        if(isprime[i]){
            for(int j = i + i; j < 3000; j += i){
                isprime[j] = false;
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int t;
    cin >> t;
    string s;
    for(int q = 1; q <= t; q ++){
        cin >> s;
        vector<int> sum(300);
        vector<int> arr;
        for(int i = 0; i < s.size(); i ++){
            sum[s[i]]++;
        }
        for(int i = 0; i < 300; i ++){
            if(isprime[sum[i]]) arr.push_back(i);
        }
        cout << "Case " << q << ": ";
        if(arr.empty()) cout << "empty\n";
        else{
            for(auto &a: arr){
                cout << char(a);
            }
            cout << '\n';
        }
    }

    return 0;
}