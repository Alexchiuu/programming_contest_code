#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 1000;

int cht[MAX];

void init(){
    for(int i = 1e5; i > 0; i --){
        int sum = i;
        int res = i;
        while(sum > 0){
            res += sum % 10;
            sum /= 10;
        }
        cht[res] = i;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    int t;
    cin >> t;
    int n;
    while(t --){
        cin >> n;
        cout << cht[n] << '\n';
    }

    return 0;
}