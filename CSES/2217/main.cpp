#include <bits/stdc++.h> 
 
using namespace std;
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m; cin>>n>>m;
    int l = 1;
    int ind[n+2] = {0};
    int ori[n+1] = {0};
    ind[n + 1] = 2147483647;
    for (int i = 1; i <= n; i++) {
    	int x; cin>>x;
    	ind[x] = i;
        ori[i] = x;
    }
    int c = 1;
    for(int i = 1; i <= n; i++){
        if(ind[i] < l){
            c++;
        }
        l = ind[i];
    }
    for(int j = 0; j < m; j++){
        int a,b;
        int oria{},oria1{},orib{},orib1{};
        int chaa{},chaa1{},chab{},chab1{};
        cin >> a >> b;
        if(ind[ori[a]] < ind[ori[a] - 1]){
            oria = 1;
        }
        if(ind[ori[a] + 1] < ind[ori[a]]){
            oria1 = 1;
        }
        if(ind[ori[b]] < ind[ori[b] - 1]){
            orib = 1;
        }
        if(ind[ori[b] + 1] < ind[ori[b]]){
            orib1 = 1;
        }
        
        int swap = ind[ori[a]];
        ind[ori[a]] = ind[ori[b]];
        ind[ori[b]] = swap;
        
        if(ind[ori[a]] < ind[ori[a]-1]){
            chaa = 1;
        }
        if(ind[ori[a]+1] < ind[ori[a]]){
            chaa1 = 1;
        }
        if(ind[ori[b]] < ind[ori[b]-1]){
            chab = 1;
        }
        if(ind[ori[b]+1] < ind[ori[b]]){
            chab1 = 1;
        }
        if(ori[a] - ori[b] == 1){
            c = c + chaa1 + chab + chab1 - oria1 - orib - orib1;
        }else if(ori[b] - ori[a] == 1){
            c = c + chaa + chaa1 + chab1 - oria - oria1 - orib1;
        }else{
            c = c + chaa + chaa1 + chab + chab1 - oria - oria1 - orib - orib1;
        }
        swap = ori[a];
        ori[a] = ori[b];
        ori[b] = swap;
        
        cout << c << "\n";
    }
    return 0;
}