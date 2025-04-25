#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        if(a[0] == b[0]){
            cout << "YES\n";
            cout << a[0] << '*' << '\n';
        }else if(a.back() == b.back()){
            cout << "YES\n";
            cout << '*' << a.back() << '\n';
        }else{
            bool check = false;
            for(int j = 0; j < a.size() - 1; j ++){
                for(int k = 0; k < b.size() - 1; k ++){
                    if(a[j] == b[k] && a[j + 1] == b[k + 1]){
                        cout << "YES\n";
                        cout << '*' << a[j] << a[j + 1] << '*' << '\n';
                        check = true;
                        break;
                    }
                }
                if(check) break;
            }
            if(check == false) cout << "NO" << '\n';
        }
    }

    return 0;
}