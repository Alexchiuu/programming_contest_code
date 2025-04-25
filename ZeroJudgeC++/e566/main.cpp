#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ,m;
    while(cin >> n >> m){
        if(m == 1 || m == 0){
            cout << "Boring!\n";
        }
        else{
            bool check = true;
            vector<int> ans;
            while(n != 1){
                if(n % m == 0){
                    ans.push_back(n);
                    n /= m;
                }else{
                    check = false;
                    break;
                }
            }
            if(check){
                for(int i = 0; i < ans.size(); i ++){
                    cout << ans[i] << ' ';
                }cout << 1 << '\n';
            }else{
                cout << "Boring!\n";
            }
        }
    }

    return 0;
}