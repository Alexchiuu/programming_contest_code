#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    multiset <int> arr;
    int input;
    while(cin >> input){
        if(input == 1){
            cin >> input;
            arr.insert(input);
        }else if(input == 3){
            cout << *(arr.begin()) << '\n';
            arr.erase(arr.begin());
        }else{
            cout << *(--arr.end()) << '\n';
            arr.erase(--arr.end());
        }
    }

    return 0;
}