#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<int,int> arr;

    int n, k;
    cin >> n >> k;
    int input;

    for(int i = 1; i <= n; i++){
        cin >> input;
        arr.insert({input,i});
    }

    for(int i = 0; i < k; i++){
        cin >> input;
        map<int,int>::iterator it = arr.lower_bound(input);
        if(it != arr.end() && (*it).first == input){
            cout << (*it).second << '\n';
        }else{
            cout << 0 << '\n';
        }
    }

    return 0;
}