#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        int k;
        cin >> k >> k;
        string s1, s2;
        int r = 0, b = 0;
        cin >> s1;
        for(int j = 0; j < s1.size(); j ++){
            if(s1[j] == 'R') r++;
            else if(s1[j] == 'B') b++;
        }
        cin >> s2;
        for(int j = 0; j < s2.size(); j ++){
            if(s2[j] == 'R') r++;
            else if(s2[j] == 'B') b++;
        }
        if(s1[0] == 'R' && s2[0] == 'R' && (r - b > 2 || b > r)) cout << "NO\n";
        else if(s1[0] == 'B' && s2[0] == 'B' && (b - r > 2 || r > b)) cout << "NO\n";
        else if(s1[0] != s2[0] && abs(b - r) > 1) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}