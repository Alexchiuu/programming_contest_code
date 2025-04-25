#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<string,int> arr;
    string s;
    while(getline(cin,s)){
        arr[s] ++;
        if (arr[s] > 1){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }

    return 0;
}