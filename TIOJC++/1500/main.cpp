#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=5e4+30;

typedef pair<int,int> p;
p P[N];
bool cmp(int a,int b){
    return P[a].second<P[b].second;
}
long long DQ(int l,int r){
    if(l==r) return 8e18;
    int mid=l+(r-l)/2,cur=min(DQ(l,mid),DQ(mid+1,r));
    vector<int> V;
    for(int i=l;i<=r;i++) if(abs(P[i].first-P[mid].first)*abs(P[i].first-P[mid].first)<cur) V.push_back(i);
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<V.size();i++){
        for(int j=max(0LL,i-10);j<i;j++){
            int x=(P[V[i]].first-P[V[j]].first),y=(P[V[i]].second-P[V[j]].second);
            if(cur>x*x+y*y) cur=x*x+y*y;
        }
    }
    return cur;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>P[i].first>>P[i].second;
    sort(P,P+n);
    cout<<DQ(0,n-1)<<"\n";
}