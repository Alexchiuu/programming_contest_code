#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    string tree;
    getline(cin,tree);
    cin.ignore();
    while(n --){
        map<string,double> fst;
        double sum = 0;
        while(getline(cin,tree) && !tree.empty()){
            fst[tree] ++;
            sum ++;
        }
        cout << tree << '\n';
        for(auto &a: fst){
            cout << a.first << ' ' << fixed << setprecision(4) << a.second / sum * 100 << '\n';
        }
    }

    return 0;
}