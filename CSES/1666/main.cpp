#include <bits/stdc++.h> 

using namespace std;

const int MAX = 1e5 + 10;

int dsu[MAX] = {};

void init(int n){
    for(int i = 1; i <= n; i ++){
        dsu[i] = i;
    }
}

int query(int n){
    if(dsu[n] == n){
        return n;
    }else{
        int tem = query(dsu[n]);
        dsu[n] = tem;
        return tem;
    }
}

void onion(int a,int b){
    int ta = query(a),tb = query(b);
    dsu[max(ta,tb)] = dsu[min(ta,tb)];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    init(n);
    int a, b;
    while(m --){
        cin >> a >> b;
        onion(a,b);
    }
    set<int> ans;
    for(int i = 1; i <= n; i ++){
        ans.insert(query(i));
    }
    cout << ans.size() - 1 << '\n';
    for(set<int>::iterator it = ++ans.begin();it != ans.end(); it ++){
        cout << (*--it) << ' ' << (*++it) << '\n';
    }


    return 0;
    
}