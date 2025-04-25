#include <bits/stdc++.h> 

using namespace std;

const int chart[26] = {0,2,4,6,8,10,12,14,16,18,20,22,24,25,23,21,19,17,15,13,11,9,7,5,3,1};

bool cmp(string a,string b){
    int x;
    if(a.size() <= b.size()) x = a.size();
    else x = b.size();
    for(int i = 0; i < x; i++){
        if(chart[a[i] - 'a'] < chart[b[i] - 'a']) return true;
        else if (chart[a[i] - 'a'] > chart[b[i] - 'a']) return false;
    }
    if(a.size() < b.size()) return true;
    else return false;
}

int main(){

    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(),cmp);
    for(auto &a: arr){
        cout << a << endl;
    }

    return 0;
    
}