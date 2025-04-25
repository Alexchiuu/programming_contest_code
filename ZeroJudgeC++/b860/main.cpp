#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int candy,bug;
    int sum = 0;
    cin >> candy >> bug;
    while(bug >= 1){
        if(candy >= 12){
            candy -= 10;
            bug --;
            sum ++;
        }else{
            bug --;
            candy ++;
        }
    }
    cout << sum << '\n';

    return 0;
}