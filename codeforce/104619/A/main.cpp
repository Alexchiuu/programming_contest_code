#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;
    int y = 0, m = 0, d = 0;
    int dy = 2023, dm = 9, dd = 16;
    y = (s[0] - '0') * 1000 +  (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
    m = (s[5] - '0') * 10 + (s[6] - '0');
    d = (s[8] - '0') * 10 + (s[9] - '0');
    if(y < dy) cout << "GOOD\n";
    else if(y == dy && m < dm) cout << "GOOD\n";
    else if(m == dm && d <= dd) cout << "GOOD\n";
    else cout << "TOO LATE\n";

    return 0;
}