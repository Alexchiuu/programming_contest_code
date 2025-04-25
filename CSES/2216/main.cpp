#include <bits/stdc++.h> 

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> sum;

    int num;
    for(int i = 0; i < n; i ++){
        cin >> num;
        auto it = upper_bound(sum.begin(),sum.end(),num * -1);
        if(it == sum.end()){
            sum.push_back(*it * -1);
        }else{
            *it = 
        }
    }
    return 0;
    
}