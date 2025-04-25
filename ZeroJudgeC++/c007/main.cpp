#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    bool check = true;
    while (getline(cin,s)){
        for(int i = 0; i < s.size(); i ++){
            if(check && s[i] == '\"'){
                check = false;
                s[i] = '\n';
            }else if(s[i] == '\"') check = true;
        }
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '\n') cout << "``";
            else if(s[i] == '\"') cout << "\'\'";
            else cout << s[i];
        }cout << '\n';
    }
    return 0;
}