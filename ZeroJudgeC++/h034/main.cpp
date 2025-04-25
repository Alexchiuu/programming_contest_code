#include <bits/stdc++.h>

using namespace std;

vector<vector<char> > g(210,vector<char> (110));

int main(){

    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j ++){
            g[i][j] = s[j];
        }
    }
    for(int i = 0; i < 100; i ++){
        for(int j = 0; j < n; j ++){
            if(isalpha(g[j][i])) cout << g[j][i];
        }
    }
    cout << '\n';
    return 0;
}