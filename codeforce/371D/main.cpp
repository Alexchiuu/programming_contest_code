#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+10;

int n;
int dsu[MAX];
vector<int> a(MAX);

void init(){
    for(int i = 1; i < MAX; i ++){
        dsu[i] = i;
    }
}

int find(int x){
    //cout << "find" << x << '\n';
    if(x == dsu[x]){
        return x;
    }else{
        return find(dsu[x]);
    }
}

void join(int x, int y){
    //cout << "ccc\n";
    dsu[x] = find(x); dsu[y] = find(y);
    //cout << "ddd\n";
    if(dsu[x] > dsu[y]){
        swap(y,x);
    }
    dsu[x] = dsu[y];
}

void pour(int p, int x){
    p = dsu[p];
    if(p == n + 1) return;
    if(x > a[p]){
        //cout << "aaa\n";
        x -= a[p];
        a[p] = 0;
        join(p, p + 1);
        //cout << p << ' ' << dsu[p] << ' ' << dsu[p + 1] << '\n';
        pour(p ,x);
        //cout << "bbb\n";
    }else{
        a[dsu[p]] -= x;
    }
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    init();

    int q;
    cin >> n;
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        b[i] = a[i];
    }
    cin >> q;

    int k, p, x;
    while(q --){
        cin >> k;
        if(k == 1){

            cin >> p >> x;
            pour(p,x);
        }else{
            cin >> p;
            //cout << b[p] << ' ' << a[p] << '\n';
            cout << b[p] - a[p] << '\n';
        }
    }

    return 0;
}