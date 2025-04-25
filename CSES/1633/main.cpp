#include <bits/stdc++.h> 

using namespace std;

const int large = 1E9 + 7;

int main(){

    int n;
    cin >> n;
    vector<long long> arr = {0,1,2,4,8,16,32};
    
    for(int i = 7; i <= n; i ++){
        arr.push_back((arr[i-1] + arr[i-2] + arr[i-3] + arr[i-4] + arr[i-5] + arr[i-6]) % large);
    }
    cout << arr[n] << endl;

    return 0;
    
}