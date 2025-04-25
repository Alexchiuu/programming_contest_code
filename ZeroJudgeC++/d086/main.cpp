#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while(getline(cin,s) && s != "0"){
        int sum = 0;
        bool check = true;
        for(auto &a: s){
            if('a' <= a && a <= 'z'){
                sum += a - 'a' + 1;
            }else if('A' <= a && a <= 'Z'){
                sum += a - 'A' + 1;
            }else{
                check = false;
                break;
            }
        }
        if(check){
            cout << sum << '\n';
        }else{
            cout << "Fail\n";
        }
    }

    return 0;
}