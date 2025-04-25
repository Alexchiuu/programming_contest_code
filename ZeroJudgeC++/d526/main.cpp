#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node * lt = nullptr;
    node * rt = nullptr;
    
    void update(int x){
        if(x < data){
            if(!lt){
                lt = new node();
                (*lt).data = x;
            }else{
                lt -> update(x);
            }
        }
        if(x > data){
            if(!rt){
                rt = new node();
                (*rt).data = x;
            }else{
                rt -> update(x);
            }
        }
    }

    void DFS(){
        cout << data << ' ';
        if(lt) lt -> DFS();
        if(rt) rt -> DFS();
    }
};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        node * d = new node();
        cin >> d->data;
        int x;
        for(int i = 1; i < n; i ++){
            cin >> x;
            d -> update(x);
        }
        d -> DFS();
        cout << '\n';
    }

    return 0;
}