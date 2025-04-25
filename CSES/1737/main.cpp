#include <bits/stdc++.h> 

using namespace std;

const int MAX = 2e5 + 10;

int arr[MAX] = {};

struct node{
    long long val;
    int l,r;
    node *lt = nullptr;
    node *rt = nullptr;
    node(int l, int r, long long val): l(l),r(r),val(val) {};

    void build(int l,int r){
        if(l == r){
            val = arr[l];
        }else{
            int mid = (l + r) / 2;
            lt = new node(l,mid,0);
            rt = new node(mid + 1, r,0);
            lt -> build(l,mid);
            rt -> build(mid + 1,r);
            val = (*lt).val + (*rt).val;
        }
        //cout << "val(" << l << ", " << r << ") =" << val << '\n';
    }

    void modify(int ind, int k){
		if(l == r){
            val = k;
        }
        else{
            int mid = (l+r)/2;
            if(ind <= mid) {
                node * s = lt;
                lt = new node(l,mid,0);
                (*lt).lt = (*s).lt;
                (*lt).rt = (*s).rt;
                lt -> modify(ind,k);
            }else{
                node * s = rt;
                rt = new node(mid + 1,r,0);
                (*rt).lt = (*s).lt;
                (*rt).rt = (*s).rt;
                rt -> modify(ind,k);
            }
            val = (*lt).val + (*rt).val;
        }
        //cout << "val(" << l << ", " << r << ") =" << val << '\n';
	}

    long long query(int ql, int qr){
        if(ql == l && qr == r){
            //cout << ql << ' ' << qr << '=' << val << '\n';
            return val;
        }
        else{
            int mid = (l+r)/2;
            if(ql > mid){
                return rt->query(ql,qr);
            }else if(qr <= mid){
                return lt->query(ql,qr);
            }else return rt->query(mid + 1,qr) + lt->query(ql,mid);
            //cout << ql << ' ' << qr << '=' << ans << '\n';
        }
    }
};



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    vector<node *> st(2);
    st[1] = new node(1,n,0);
    st[1]->build(1,n);
    
    int t;
    while(q --){
        cin >> t;
        if(t == 1){
            int k, a, x;
            cin >> k >> a >> x;
            st[k] -> modify(a,x);
        }else if(t == 2){
            int k, a, b;
            cin >> k >> a >> b;
            cout << st[k] -> query(a,b) << '\n';
        }else if(t == 3){
            int k;
            cin >> k;
            st.push_back(new node(1,n,(*st[k]).val));
            (*st.back()).lt = (*st[k]).lt;
            (*st.back()).rt = (*st[k]).rt;
        }
    }
    

    return 0;
    
}