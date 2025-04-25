#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;

    cin >> N;

    vector<int> v(N,-1);
    stack<pair<int,int>> unseen;

    int height;
    for(int i = 0; i < N; i++){
        cin >> height;
        while(!unseen.empty() && height >= unseen.top().first){
            v[unseen.top().second] = i - unseen.top().second;
            unseen.pop();
        }
        unseen.push({height,i});
    }
    for(int i = 0; i < N; i++){
        if(v[i] == -1){
            cout << N - 1 - i << endl;
        }else{
            cout << v[i] << endl;
        }
    }

    return 0;
    
}