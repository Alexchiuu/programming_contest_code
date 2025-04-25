#include <bits/stdc++.h>

using namespace std;

int dsu[200000];

void init(int n){
    for(int i = 1; i <= n; i++){
        dsu[i] = i;
    }
}

int query(int x){
    if(x == dsu[x]) return x;
    int tmp = query(dsu[x]);
    dsu[x] = tmp;
    return tmp;
}

void onion(int x, int y){
    int a = query(x), b = query(y);

    dsu[max(a,b)] = min(a,b);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int a, b;
    init(N);
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        onion(a,b);
    }
    long long sum = 0;
    for(int i = 0; i < N; i++){
        if(query(i) == 0) sum ++;
    }
    cout << sum << '\n';
    return 0;
}