#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n + 2,0);
    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
    }
    int inf = n;
    int inb = 1;
    for(int i = 1; i <= n; i ++){
        if(arr[i] == 1){
            inf = i;
            break;
        }
    }
    for(int i = n; i >= 1; i --){
        if(arr[i] == 1){
            inb = i;
            break;
        }
    }
    for(int i = 1; i <= n; i ++){
        if(arr[i] == 9){
            arr[i - 1] = 1;
            arr[i] = 1;
            arr[i + 1] = 1;
        }
    }
    if(inb - inf <= 0){
        cout << 0 << '\n';
    }else{
        int sum = 0;
        for(int i = inf + 1; i < inb; i ++){
            if(arr[i] == 0) sum ++;
        }
        cout << sum << '\n';
    }

    return 0;
}