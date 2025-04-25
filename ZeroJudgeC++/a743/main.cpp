#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string c, p;
    map<string,int> l;
    while(n --){
        cin >> c;
        getline(cin,p);
        l[c]++;
    }
    for(auto &a: l){
        cout << a.first << ' ' << a.second << '\n';
    }

    return 0;
}