#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    int n, m;
    cin >> m >> n;
    string s, T;
    vector<string> codemasks (m);
    for(int i = 0; i < m; i++){
        cin >> codemasks[i];
        int count = 0;
        for(int j = 0; j < n; j++){
            if(codemasks[i][j] == '1'){
                count ++;
            }
        }
        if(count % 2 == 1){
            codemasks[i].push_back('1');
        }else{
            codemasks[i].push_back('0');
        }
    }
    cin >> T;
    int ifodd = n % 2;
    for(int i = m - 1; i >= 0; i--){
        int pointl = 0;
        int pointr = n - 1;
        
        for(int j = n - 1; j >= 0; j--){
            if(codemasks[i][j] == '1'){
                s.push_back(T[j]);
            }else{
                s.insert(s.begin(),T[j]);
            }
        }
        if(codemasks[i][n] == '1'){
            string sc = s;
            sc.replace(n / 2 + ifodd, n / 2, s.substr(0, n / 2));
            sc.replace(0, n / 2, s.substr(n / 2 + ifodd, n / 2));
            T = sc;
        }else{
            T = s;
        }
        s.clear();

    }
    cout << T << endl;

    return 0;
    
}