#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    map<int,int> subar;
    int l, r;
    while(n --){
        cin >> l >> r;
        map<int,int>::iterator it = subar.lower_bound(l);
        if(it == subar.end()){
            subar.insert({l,r});
        }else{
            if(r > (*it).first)
        
        }
    }

    return 0;
}