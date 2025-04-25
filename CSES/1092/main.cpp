#include <bits/stdc++.h> 

using namespace std;

int main(){

    long long n;
    cin >> n;

    if(n * (n + 1) / 2 % 2 == 1){
        cout << "NO" << endl;
    }else{
        vector<long long> a;
        vector<long long> b;
        long long suma = 0, sumb = 0;
        for(int i = n; i > 0; i--){
            if(sumb > suma){
                a.push_back(i);
                suma += i;
            }else{
                b.push_back(i);
                sumb += i;
            }
        }
        cout << "YES" << endl;
        cout << a.size() << endl;
        for(int i = a.size() - 1; i >= 0; i--){
            cout << a[i] << ' ';
        }
        cout << endl;
        cout << b.size() << endl;
        for(int i = b.size() - 1; i >= 0; i--){
            cout << b[i] << ' ';
        }
        cout << endl;
    }

    return 0;
    
}