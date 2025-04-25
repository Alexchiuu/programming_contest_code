#include <bits/stdc++.h> 
 
using namespace std;
 
vector<bool> x(10,false);
vector<bool> yax(19,false);
vector<bool> ymx(19,false);
vector<bool> cyax(19,false);
vector<bool> cymx(19,false);
 
int f(int M, int N,int q,int c,int l){
    int sum = 0;
    if(l == M + N - 1){
        for(int i = 0; i < M + N; i++){
            if(yax[l + i]) continue;
            if(ymx[l - i + 9]) continue;
            if(x[i]) continue;
            if(q < M){
                if(cyax[l + i]) continue;
                if(cymx[l - i + 9]) continue;
            }
            sum ++;
        }
        return sum;
    }
    for(int i = 0; i < M + N; i++){
        if(yax[l + i]) continue;
        if(ymx[l - i + 9]) continue;
        if(x[i]) continue;
        if(q < M){
            if(cyax[l + i]) continue;
            if(cymx[l - i + 9]) continue;
            x[i] = true;
            yax[l + i] = true;
            ymx[l - i + 9] = true;
            sum += f(M,N,q+1,c,l+1);
            x[i] = false;
            yax[l + i] = false;
            ymx[l - i + 9] = false;
        }
        if(c < N){
            x[i] = true;
            cyax[l + i] = true;
            cymx[l - i + 9] = true;
            sum += f(M,N,q,c+1,l+1);
            x[i] = false;
            cyax[l + i] = false;
            cymx[l - i + 9] = false;
        }
    }
    return sum;
}
 
int main(){
 
    int M, N;
    cin >> M >> N;
    cout << f(M,N,0,0,0) << endl;
 
    return 0;

}