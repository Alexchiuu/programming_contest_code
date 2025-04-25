#include <bits/stdc++.h> 
#define ll long long

using namespace std;

int main(){

    int n;
    cin >> n;
    ll last = 0;
    ll now;
    ll sum = 0;
    bool h = false;
    for(int i = 0; i < n; i++){
        cin >> now;
        if(h){
            if(now < last){
                h = false;
                sum ++;
            }
        }else{
            if(now > last){
                h = true;
                sum ++;
            }
        }
        last = now;
    }
    if(!h) sum --;
    cout << sum << '\n';

    return 0;
    
}