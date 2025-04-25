#include <bits/stdc++.h> 

using namespace std;

int main(){

    int n;
    cin >> n;
    int x[n + 1] = {0};
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
        if(x[i] < x[i - 1]){
            sum += (x[i - 1] - x[i]);
            x[i] = x[i - 1];
        }
    }

    cout << sum << endl;

    return 0;
    
}