#include <bits/stdc++.h> 
#define int long long 
using namespace std;
const int m=998244353,base=127;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s,t;
    cin>>s;
    int n;
    cin>>n;
    int lens=s.length();
    vector<int> ps(lens+1);
    ps[0]=0;
    for(int i=1;i<=lens;i++){
        ps[i]=ps[i-1]*base+s[i-1];
        ps[i]%=m;
    }
    vector<int> bases(1020);
    bases[0]=1;
    for(int i=1;i<1020;i++) bases[i]=(bases[i-1]*base)%m;
    for(int i=0;i<n;i++){
        cin>>t;
        int lent=t.length();
        vector<int> pt(lent+1);
        pt[0]=0;
        for(int j=1;j<=lent;j++){
            pt[j]=pt[j-1]*base+t[j-1];
            pt[j]%=m;
        }
        int ans=-1;
        for(int j=1;j<=min(lens,lent);j++){
            if(pt[j]%m==(ps[lens]-(ps[lens-j]*bases[j]%m)+m)%m) ans=max(ans,min(j,lent-j));
        }
        cout<<ans<<"\n";
    }
    
}