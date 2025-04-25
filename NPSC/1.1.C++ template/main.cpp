#include <bits/stdc++.h> 

using namespace std;

int main(){

    int n, m, s, f;
    cin >> n >> m >> s >> f;
    vector<pair<int,int> > arr(m);
    vector<string> g(n);
    vector<bool> isempty(m);
    for(int i = 0; i < n; i ++){
        cin >> g[i];
    }
    for(int i = 0; i < m; i ++){
        int l = n - 1, r = 0;
        for(int j = 0; j < n; j ++){
            if(g[j][i] == '1'){
                l = j;
                break;
            }
        }
        for(int j = n - 1; j >= 0; j --){
            if(g[j][i] == '1'){
                r = j;
                break;
            }
        }
        if(l== n - 1 && r == 0) isempty[i] = true;

        arr[i] = {l,r};
    }


    pair<int,int> lstrangeup = {s,s};
    pair<int,int> lstrangedown = {s,s};
    int chk = true;
    for(int i = 0; i < m; i ++){

        if(isempty[i]){
            lstrangeup = {0,n - 1};
            lstrangedown = {0, n - 1};
        }
        bool flag = false;
        if(lstrangeup.first <= arr[i].first && lstrangeup.second >= arr[i].second){
            lstrangeup = {0,arr[i].first};
            lstrangedown = {arr[i].second, n - 1};
        }else if(lstrangedown.first <= arr[i].first && lstrangedown.second >= arr[i].second){
            lstrangeup = {0,arr[i].first};
            lstrangedown = {arr[i].second, n - 1};
        }else if(lstrangeup.first > arr[i].first && lstrangeup.second < arr[i].second && lstrangedown.first > arr[i].first && lstrangedown.second < arr[i].second){
            chk = false;
            break;
        }else{
            pair<int,int> tmp2;
            if(lstrangeup.first <= arr[i].first || lstrangedown.first <= arr[i].first){
                tmp2 = {arr[i].second, n - 1};
                flag = true;
            }
            if(lstrangeup.second >= arr[i].second || lstrangedown.second >= arr[i].second){
                lstrangeup = {0,arr[i].first};
                if(flag == false){
                    tmp2 = lstrangeup;
                }
            }else{
                if(flag == false){
                    chk = false;
                    break;
                }else{
                    lstrangeup = tmp2;
                }
            }
            lstrangedown = tmp2;
        }
        
    }

    if(chk && (lstrangeup.first <= f && f <= lstrangeup.second) || (lstrangedown.first <= f && f <= lstrangedown.second)){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    return 0;
    
}