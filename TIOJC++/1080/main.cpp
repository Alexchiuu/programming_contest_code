#include <bits/stdc++.h> 

using namespace std;

const int N=1e5+30;
long long arr[N],b[N];

long long summing(int l,int r){
    if(l==r) return 0;
    int mid=(r+l)/2;
    long long sum = summing(l,mid) + summing(mid+1,r);
    for(int i=l;i<=r;i++) b[i]=arr[i];
    int x=l,y=mid+1,cur=l;
    while(x<=mid&&y<=r){
    	if(b[x]<=b[y]){
            arr[cur]=b[x];
            x++;
        }else{
            arr[cur]=b[y];
            y++;
            sum += mid - x + 1;
        }
        cur++;
    }
    while(x<=mid){
    	arr[cur]=b[x];
        cur++,x++;
    }
    while(y<=r){
    	arr[cur]=b[y];
        cur++,y++;
    }
    return sum;
}
int main(){

    int n;
    int t = 1;
    while(cin >> n && n != 0){
        int input;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << "Case #" << t << ": " << summing(0,n - 1) << endl;
        t += 1;
    }

    return 0;
    
}