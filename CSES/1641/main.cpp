#include <bits/stdc++.h> 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){

    int n, x;

    cin >> n >> x;
    vector<pair<int,int> > arr(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    if(n < 3){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    sort(arr.begin(),arr.end());

    bool flag = false;

    for(int i = 0; i < n; i++){
        int j, k;
        if(i == 0) j = 1;
        else j = 0;
        if(i == n-1) k = n - 2;
        else k = n - 1;
        while(arr[i].first + arr[j].first + arr[k].first != x && j != k){
            //cout << arr[i].first + arr[j].first + arr[k].first << '\n';
            if(arr[i].first + arr[j].first + arr[k].first < x){
                if(j + 1 == i) j += 2;
                else j ++;
            }else{
                if(k - 1 == i) k -= 2;
                else k --;
            }
        }
        //cout << arr[i].first + arr[j].first + arr[k].first << '\n';
        if(arr[i].first + arr[j].first + arr[k].first == x && j != k){
            flag = true;
            cout << arr[i].second << ' ' << arr[j].second << ' ' << arr[k].second << '\n';
            break;
        }
    }
    if(!flag) cout << "IMPOSSIBLE\n";

    return 0;    
}