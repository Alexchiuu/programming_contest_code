#include <bits/stdc++.h>
#define int long long

using namespace std;

bool iscur(int n, int k){
    if(k == 1) return  false;
    vector<int> arr;
    while(n != 0){
        arr.push_back(n % k);
        n /= k;
    }
    for(int i = 0; i < arr.size() / 2; i ++){
        if(arr[i] != arr[arr.size() - i - 1]){
            return false;
        }
    }
    return true;
}


signed main(){

    int n;
    cin >> n;
    set<int> ans;
    for(int i = 1; i < sqrt(n); i ++){
        if(i + 1 == n / i) continue;
        if(n % i == 0){
            ans.insert((n / i) - 1);
        }
    }
    for(int i = 2; i <= sqrt(n); i ++){
        if(iscur(n,i)){
            ans.insert(i);
        }
    }

    if(ans.size() == 0){
        cout << "*\n";
    }else{
        for(auto & a: ans) cout << a << ' ';
        cout << '\n';
    }

    return 0;
}