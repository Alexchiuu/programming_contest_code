#include <bits/stdc++.h> 

using namespace std;

int main(){

    map<int,int> t;
    map<int,int> input;
    int s, f;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> f;
        if(input[s] == 0 || input[s] < f) input[s] = f;
    }
    for(auto &a: input) {
        if(t[a.second] < t[a.first] + 1) t[a.second] = t[a.first] + 1;
    }
    return 0;
    
}