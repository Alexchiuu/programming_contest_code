#include <bits/stdc++.h> 

using namespace std;

int main(){

    long long n;
    cin >> n;
    long long sum = (n * n + n) / 2;
    int input;
    for(int i = 1; i < n; i++){
        cin >> input;
        sum -= input;
    }
    cout << sum << endl;

    return 0;
    
}