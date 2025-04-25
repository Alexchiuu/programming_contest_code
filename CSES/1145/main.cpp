#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr;
    int input;
    for(int i = 0; i < n; i++){
        cin >> input;
        vector<int>::iterator it = lower_bound(arr.begin(), arr.end(), input);
        if(it == arr.end()) arr.push_back(input);
        else *it = input;
    }
    cout << arr.size() << '\n';

    return 0;
    
}