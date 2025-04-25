#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> arr;
    string s;
    while(cin >> s) arr.push_back(s);
    for(int i = 0; i < arr.size() - 1; i++){
        cout << arr[arr.size() - 1] << ", " << arr[i] << '\n';
    }
    return 0;
}