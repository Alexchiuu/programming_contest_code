#include <bits/stdc++.h>

using namespace std;

int dsu[500];

void init(){
    for(int i = 1; i <= 400; i ++){
        dsu[i] = i;
    }
}

int par(int x){
    //cout << x << '\n';
    if(x == dsu[x]) return x;
    else{
        dsu[x] = par(dsu[x]);
        return dsu[x];
    }
}

void onion(int a, int b){
    a = par(a);
    b = par(b);
    dsu[a] = b;
}

int main(){

    init();
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
    }

    string s;
    for(int i = 1; i <= n; i ++){
        cin >> s;
        for(int j = 0; j < n; j ++){
            if(s[j] == '1'){
                onion(i,j + 1);
            }
        }
    }

    map<int,vector<int>> mp1;
    map<int,vector<int>> mp2;
    vector<int> gps;
    for(int i = 1; i <= n; i ++){
        
        int sv = i;
        sv = par(sv);
        mp1[sv].push_back(i);
        mp2[sv].push_back(arr[i]);
        gps.push_back(sv);
        //cout << "ss" << sv << '\n';
    }

    vector<int> ans(n+1);
    for(int i = 0; i < gps.size(); i ++){
        sort(mp2[gps[i]].begin(),mp2[gps[i]].end());
        /*
        for(auto &a :mp2[gps[i]]){
            cout << a << ' ';
        }cout << '\n';
        for(auto &a :mp1[gps[i]]){
            cout << a << ' ';
        }cout << '\n';
        */
        for(int j = 0; j < mp2[gps[i]].size(); j ++){
            ans[mp1[gps[i]][j]] = mp2[gps[i]][j];
        }
    }
    for(int i = 1; i <= n; i ++){
        cout << ans[i] << ' ';
    }cout << '\n';

    return 0;
}