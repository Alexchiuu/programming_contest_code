#include <bits/stdc++.h> 

using namespace std;

vector<int> prime;
bool vis[46350] = {};

void init(){
    for(int i = 2; i < 46350; i++){
        if(!vis[i]){
            prime.push_back(i);
            for(int j = i + i; j < 46350; j += i){
                vis[j] = true;
            }
        }
    }
}

int f(int l, int r){
    bool visit[r-l+1] = {};
    int sm = r - l + 1;
    for(int i = 0; i < prime.size() && prime[i] < r; i++){
        int k = l / prime[i];
        if(l % prime[i] != 0) k ++;
        if(k == 1) k ++;
        for(int j = prime[i] * k; j <= r; j += prime[i]){
            if(!visit[j - l]){
                sm --;
                visit[j - l] = true;
            }
        }
    }

    return sm;
}

int main(){

    init();

    int m;
    int l, r;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        cout << f(l,r) << '\n';
    }

    return 0;
    
}