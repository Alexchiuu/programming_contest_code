#include <bits/stdc++.h> 

using namespace std;

int seen[1000000] = {0};
bool np[1000000] = {0};
vector<int> prime;

void initialize(){
    for(int i = 2; i < 1000000; i++){
        if(!np[i]){
            prime.push_back(i);
            for(int j = i + i; j <= 1000000;j += i) np[j] = true;
        }
    }
}

int sum(int n){
    if(seen[n] != 0) return seen[n];
    if(!np[n]) return 2;
    int ans = 1;
    for(int i = 0;n != 1; i++){
        int sum = 1;
        while (n % prime[i] == 0){
            n /= prime[i];
            sum ++;
        }
        ans *= sum;
    }
    seen[n] = ans;
    return ans;
}

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    cin >> n;
    int input;
    initialize();
    for(int i = 0; i < n; i++){
        cin >> input;
        cout << sum(input) << '\n';
    }

    return 0;
    
}