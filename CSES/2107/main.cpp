#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){

    fastio

    string s;
    cin >> s;
    vector<int> kmp(s.size(),0);
    vector<int> z(s.size(),0);
    
    int l=0, r=0;
    for(int i = 1; i < s.size(); i ++){
        if(i<=r) z[i]=min(r-i+1,z[i-l]);
        while(i+z[i] < s.size()&&s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
    for(int i = 0; i < s.size(); i++) cout << z[i] << ' ';
    cout << '\n';

    for(int i = 1; i < s.size(); i ++){
        int tmp = kmp[i - 1];
        while(tmp != 0 && s[tmp] != s[i]) tmp = kmp[tmp - 1];
        if(s[tmp] == s[i]) kmp[i] = tmp + 1;
        else kmp[i] = tmp;
    }
    for(int i = 0; i < s.size(); i++) cout << kmp[i] << ' ';
    cout << '\n';

    return 0;    
}