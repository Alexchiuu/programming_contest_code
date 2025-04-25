#include <bits/stdc++.h>

using namespace std;

int main(){

    int M, N;
    cin >> M >> N;
    vector<vector<int>> graph(M,vector<int> (N));
    int input;
    int sum;
    for(int i = 0; i < M; i++){
        sum = 0;
        for(int j = 0; j < N; j++){
            cin >> input;
            if(input == 0) sum = 0;
            else sum ++,graph[i][j] = sum;
        }
    } 
    int max = 0;

    for(int i = 0; i < N; i++){
        stack<pair<int,int>> lines;
        for(int j = 0; j < M; j++){
            int save = j;
            while(!lines.empty() && lines.top().first > graph[j][i]){
                if(lines.top())
                save = lines.top().second; 
                lines.pop();
            }
            if(lines.top().first != input){
                lines.push({input,save});
            }
        }
    }

    return 0;
}