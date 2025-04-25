#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    vector<pair<int,int> > arr(26);
    cin.ignore();
    while(n --){
        getline(cin,s);
        for(int i = 0; i < s.size(); i ++){
            if('a' <= s[i] && s[i] <= 'z'){
                arr[s[i] - 'a'].second++;
            }else if('A' <= s[i] && s[i] <= 'Z'){
                arr[s[i] - 'A'].second++;
            }
        }
    }
    for(int i = 0; i < 26; i ++) arr[i].first = i;
    sort(arr.begin(),arr.end(),[] (pair<int,int> a,pair<int,int> b){
        if(a.second > b.second) return true;
        if(a.second < b.second) return false;
        return a.first < b.first;
    });
    for(int i = 0; i < 26; i ++){
        if(arr[i].second == 0) break;
            cout << char('A' + arr[i].first) << ' ' << arr[i].second << '\n';
    }

    return 0;
}