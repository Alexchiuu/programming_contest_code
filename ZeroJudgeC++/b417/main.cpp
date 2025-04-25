#include <bits/stdc++.h>

using namespace std;

struct range{
    pair<int,int> p;
    int n;
    pair<int,int> ans;
};

int main(){

    int n, m;
    vector<range> q(m);
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < m; i ++){
        cin >> q[i].p.first >> q[i].p.second;
        q[i].n = i;
    }
    sort(q.begin(),q.end(),[] (range a,range b){
        return a.p < b.p;
    });

    int reseen[100010] = {};
    int mxnum = 0;
    int mxsum = 0;
    for(int i = q[0].p.first ; i <= q[0].p.second; i ++){
        reseen[arr[i]]++;
        if(reseen[arr[i]] > mxsum){
            mxnum = arr[i];
            mxsum = reseen[arr[i]];
        }
    }
    q[0].ans.first = mxnum;
    q[0].ans.second = mxsum;
    for(int i = 1; i < m; i ++){
        for(int j = q[i - 1].p.first; j < q[i - 1].p.second;j ++){
            
        }
    }

    return 0;
}