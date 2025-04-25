#include <bits/stdc++.h> 

using namespace std;

int n;
vector<bool> p(10);

int plusone(string &k){
    string keep = k;
    k[0] ++;
    int i = 0;
    while(i != k.size() && k[i] == n + '0'){
        k[i] = '0';
        if(i + 1 == k.size()) k.push_back('1');
        else k[i + 1] ++;
        i ++;
    }
    for(int i = 0; i < keep.size(); i ++){
        if(p[k[i] - '0']){
            plusone(k);
            break;
        }
    }
    int sum = 0;
    for(int i = 0; i < keep.size(); i ++){
        if(keep[i] != k[i]) sum ++;
    }
    sum += k.size() - keep.size();
    return sum;
}


int main(){

    int k;
    cin >> n >> k;
    int input;
    for(int i = 0; i < k; i++){
        cin >> input;
        p[input] = true;
    }
    string a, b;
    cin >> a >> b;
    string o, q;
    for(int i = a.size() - 1; i >= 0; i --) o.push_back(a[i]);
    for(int i = b.size() - 1; i >= 0; i --) q.push_back(b[i]);
    a = o;
    b = q;
    
    int s = 0;
    while(a != b){
        s += plusone(a);
    }
    cout << s << '\n';

    return 0;
    
}