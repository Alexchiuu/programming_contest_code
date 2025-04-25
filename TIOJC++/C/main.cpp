#include <bits/stdc++.h> 
#define int long long

using namespace std;

const int MAX = 4e5;

int c[MAX + 1];

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K, P;
    cin >> N >> K >> P;
    for(int i = 1; i <= N; i ++) cin >> c[i];
    for(int i = 1; i <= MAX; i ++) c[i] += c[i - 1];

    int sum = 0;
    int ind = 1;
    while(ind <= N){
        priority_queue<int> pq;
        int tmp = ind;
        for(ind; ind < tmp + K; ind ++){
            pq.push(c[ind]-c[ind - 1]);
            sum += c[ind]-c[ind - 1];
        }
        sum -= P;
        if(ind > N) break;
        //cout << c[ind + K - 1] - c[ind - 1] - P << "vs" << (c[ind] - c[ind - 1])-max(pq.top(), (c[ind] - c[ind - 1])) << '\n';
        while(c[ind + K - 1] - c[ind - 1] - P <= (c[ind] - c[ind - 1])-max(pq.top(), (c[ind] - c[ind - 1])) && ind <= N){
            sum += (c[ind] - c[ind - 1]) - max(pq.top(), (c[ind] - c[ind - 1]));
            if(pq.top() > (c[ind] - c[ind - 1])){
                pq.pop();
                pq.push((c[ind] - c[ind - 1]));
            }
            ind ++;
        }
    }
    cout << sum << '\n';
    return 0;
    
}