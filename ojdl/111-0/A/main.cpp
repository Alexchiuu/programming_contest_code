#include <bits/stdc++.h> 

using namespace std;

int main(){
    int N, M, k, D;
    cin >> N >> M >> k >> D;

    priority_queue<int> pq;
    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        pq.push(input); 
    }

    int sum = 0;
    int s = min(N - D, k);
    for(int i = 0; i < s; i++){
        
    } 

    return 0;
    
}