#include <bits/stdc++.h> 

using namespace std;

set<int> arr;

int bs(int k,int l, int r){
    if(l == r){
        return l;
    }else{
        int mid = (l + r) / 2;
        if(arr.find(mid * k) != arr.end()){
            
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    char input;
    int num;
    while(q --){
        cin >> input >> num;
        if(input == '+'){
            arr.insert(num);
        }else{

        }
    }

    return 0;
    
}