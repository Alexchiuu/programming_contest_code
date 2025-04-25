#include <bits/stdc++.h> 

using namespace std;

const int MAX = 1e5 + 10;

int V[MAX];
int W[MAX];
int wst[MAX * 4];

struct node{
	int v;
    int t;
};

node seg_tree[MAX * 4];

void update(int l, int r, int start, int end, int ind, int tag){
	if(start>r||end<l) return;
	if(start<=l&&end>=r){
		seg_tree[ind].t += tag;
        seg_tree[ind].v += seg_tree[ind].t*(r-l+1);
		return;
	}
	int mid = (l+r)/2;
	
	update(l,mid,start,end,ind * 2,tag);
	update(mid+1,r,start,end,ind * 2 + 1,tag);
    
	seg_tree[ind].v = seg_tree[ind * 2].v + seg_tree[ind * 2 + 1].v;
}

int query(int l, int r, int start, int end, int ind){
	if(start>r||end<l) return 0;
	if(start<=l&&end>=r) return seg_tree[ind].v;
	int mid = (l+r)/2;
	seg_tree[ind * 2].t = seg_tree[ind].t;
    seg_tree[ind * 2 + 1].t += seg_tree[ind].t;
    seg_tree[ind * 2].v += (mid-l+1)*seg_tree[ind].t;
	seg_tree[ind * 2 + 1].v += (r-mid)*seg_tree[ind].t;
	seg_tree[ind].t = 0;

	return query(l,mid,start,end,lind) + query(mid+1,r,start,end,rind);
}


int main(){

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> V[i];
    }
    for(int i = 1; i <= n; i ++){
        cin >> W[i];
    }
    int input;
    vector<bool> arr(MAX,1);
    while(q --){
        cin >> input;
        if(input == 1){
            int k;
            cin >> k;
            int sumv;
            if(arr[k] == 1){
                for(int i = k - 1; i >= 0; i --){
                    if(arr[k] == 1) break;

                }
            }
            
        }
    }

    return 0;
    
}