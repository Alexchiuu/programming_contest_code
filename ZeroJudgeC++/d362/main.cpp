#include <bits/stdc++.h>

using namespace std;

const int MAX = 20000000+10;

bool check[MAX] = {};
vector<pair<int,int> > arr;

void init(){
    for(int i = 2; i < MAX; i ++){
        if(!check[i]){
            for(int j = i + i; j < MAX; j += i){
                check[j] = true;
            }
        }
    }
}

void inittp(){
    for(int i = 2; i < MAX; i++){
        if(!check[i] && !check[i + 2]){
            arr.push_back(make_pair(i,i + 2));
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    inittp();

    int n;
    while(cin >> n){
        cout << '(' << arr[n - 1].first << ", " << arr[n - 1].second << ")\n";
    }

    
    return 0;
}