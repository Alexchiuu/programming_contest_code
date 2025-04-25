#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool check = false;
        int sum = 0;
        for(int i = 0;i < s.size(); i ++){
            if(check && s[i] != s[i - 1]){
                sum ++;
            }else if(s[i] == '1'){
                check = true;
            }
        }
        cout << sum << '\n';
    }

    return 0;
    
}