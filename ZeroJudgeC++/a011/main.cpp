#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while(getline(cin,s)){
        bool check = false;
        int sum = 0;
        for(int i = 0; i < s.size(); i ++){
            if(isalpha(s[i])){
                if(check == false){
                    sum ++;
                    check = true;
                }
            }else check = false;
        }
        cout << sum << '\n';
    }

    return 0;
}