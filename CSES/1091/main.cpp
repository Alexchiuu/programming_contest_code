#include <bits/stdc++.h> 

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    multiset<long long,greater<long long>> tickets;
    long long price;
    for(int i = 0; i < n; i++){
        cin >> price;
        tickets.insert(price);
    }
    int pay;
    for(int i = 0; i < m; i++){
        cin >> pay;
        auto it = tickets.lower_bound(pay);
        if(it == tickets.end()){
            cout << -1 << endl;
        }else{
            cout << *it << endl;
            tickets.erase(it);
        }

    }

    return 0;
    
}