#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){

    string s;
    vector<int> arr;
    vector<int> zro;
    int l;
    cin >> s >> l;
    int sum = 0;
    int num = 0;
    int n = 1;

    if(s == "0"){
        cout << 0 << '\n';
        return 0;
    }
    
    for(int i = 0; i < s.size(); i ++){
        if(s[i] - '0' == 0){
            arr.back() *= 10;
            zro.back() *= 10;
        }
        else{
            arr.push_back(s[i] - '0');
            zro.push_back(10);
        }
    }
    
    int cur = 0, pzr = 1;
    for(int i = arr.size() - 1; i >= 0; i --) {
        if (arr[i]*pzr+cur <= l) {
            cur = cur+arr[i]*pzr;
            pzr += zro[i];
        } else if (cur && cur <= l) {
            l = cur;
            cur = 0;
            sum++;
            pzr = 1;
        } else {
            cout<<"NO WAY\n";
            return 0;
        }
        /*int tmp = num;
        if(tmp > l){
            num = 4e18;
            break;
        }
        num += arr[i] * n;
        if(num > l) {
            cout << tmp << '\n';
            l = tmp;
            num = 0;
            n = 1;
            num += arr[i] * n;
            sum ++;
        }
        n *= zro[i];*/
    }
    cout << sum << '\n';

    return 0;
}