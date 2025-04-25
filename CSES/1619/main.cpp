#include <bits/stdc++.h>

using namespace std;

int main(){

    map<long long int,int> m;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int time;
        cin >> time;
        m[time]++;
        cin >> time;
        m[time]--;
    }

    int max = 0;
    int sum = 0;
    for(auto &a:m){
        sum += a.second;
        if(sum > max){
            max = sum;
        }
    }

    cout << max << endl;
    
    return 0;
    
}