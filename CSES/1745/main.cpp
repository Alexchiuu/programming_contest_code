#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){

    int n;
    cin >> n;
    set<int> s;
    s.insert(0);
    int input;
    for(int i = 0; i < n; i ++){
        cin >> input;
        vector<int> arr;
        for(auto &a: s){
            arr.push_back(a + input);
        }
        for(auto &a: arr){
            s.insert(a);
        }
    }
    cout << s.size() - 1 << '\n';
    for(auto &a: s){
        if(a != 0) cout << a << ' ';
    }
    cout << '\n';
    return 0;    
}