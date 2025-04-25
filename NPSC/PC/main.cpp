#include <bits/stdc++.h> 
#define int long long
using namespace std;

vector<int> seg,arr;
void build(int l,int r,int ind){
    if(l==r){
        seg[ind]=l;
        return;
    }
    else{
        int mid=(l+r)/2;
        build(l,mid,ind*2);
        build(mid+1,r,ind*2+1);
        if(arr[seg[ind*2]]<arr[seg[ind*2+1]])seg[ind]=seg[ind*2];
        else seg[ind]=seg[ind*2+1];
        //seg[ind]=min(arr[seg[ind*2]],arr[seg[ind*2+1]]);
    }
}

int query(int l,int r,int start,int end,int ind){
    if(start>r||end<l){
        return 0;
    }
    if(start<=l&&end>=r){
        return seg[ind];
    }
    int mid=(l+r)/2;
    if(arr[query(l,mid,start,end,ind*2)]<arr[query(mid+1,r,start,end,ind*2+1)])return query(l,mid,start,end,ind*2);
    else return query(mid+1,r,start,end,ind*2+1);
    //return min(arr[query(l,mid,start,end,ind*2)],arr[query(mid+1,r,start,end,ind*2+1)]);
}

void modify(int l,int r,int num,int pos,int ind){
    if(l==r){
        seg[ind]=l;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid){
        modify(l,mid,num,pos,ind*2);
    }
    else{
        modify(mid+1,r,num,pos,ind*2+1);
    }
    if(arr[seg[ind*2]]<arr[seg[ind*2+1]])seg[ind]=seg[ind*2];
    else seg[ind]=seg[ind*2+1];
    //seg[ind]=min(arr[seg[ind*2]],arr[seg[ind*2+1]]);
}
signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t --){
        int n, k;
        cin >> n >> k;
        seg.resize(4*n + 4);
        arr.resize(n + 1);
        arr[0]=1e9+7;
        for(int i = 1; i <= n; i ++) cin >> arr[i];
        build(1,n,1);
        int j = 1;
        for(int i = 1; i <= n - k + 1; i ++){
            int l = i,r = i + k - 1;
            //cout << "l:" << l << " r:" << r << '\n';
            if(j < l) j = l;
            while(arr[j] <= arr[j + 1] && j < r) j ++;
            if(j == r) continue;
            //cout << "j: " << j << '\n';
            int ind = query(1,n,j,r,1);
            vector<int>::iterator it = upper_bound(arr.begin() + l, arr.begin() + j + 1,arr[ind]);
            int tmp = arr[ind];
            swap(arr[ind],arr[it - arr.begin()]);
            modify(1,n,it - arr.begin(),ind,1);
            modify(1,n,ind,it - arr.begin(),1);
            /*
            for(int p = 1; p <= n; p++){
                cout << arr[p] << ' ';
            }cout << '\n';
            */
        }
        cout<<arr[1];
        for(int i = 2; i <= n; i++){
            cout <<" "<< arr[i];
        }cout << '\n';
    }

    return 0;
    
}