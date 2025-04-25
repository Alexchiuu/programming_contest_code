#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while(cin >> s){
        int j = 0;
        int sum = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == 'y'){
                sum += abs(i - j);
                j += 3;
            }
        }
        cout << sum << '\n';
    }

    return 0;
}