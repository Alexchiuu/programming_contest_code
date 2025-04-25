#include <bits/stdc++.h> 

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    map<int,int> seen;
    int sum = 1;
    int i = 1, j = 1;
    while(j <= n){
        if(seen[arr[j]] >= i){
            i = seen[arr[j]] + 1;
        }
        seen[arr[j]] = j;
        sum = max(sum,j - i + 1);
        j ++;
    }
    cout << sum << '\n';

    return 0;
    
}