#include <bits/stdc++.h> 

using namespace std;

int f(vector<bool> &used,vector<int> arr,int n,int sum){
    long long min = 21483647000000;
    for(int i = 0; i < arr.size(); i++){
        if(sum + arr[i] > n) return n - sum;
        if(!used[i]){
            sum += arr[i];
            used[i] = true;
            int x = f(used,arr,n,sum);
            sum -= arr[i];
            used[i] = false;
            if(x < min) min = x;
        }
    }
    return min;
}

int main(){

    int n;
    cin >> n;

    vector<int> arr(n); 
    int input;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(),arr.end());

    vector<bool> used(n,false);

    cout << f(used,arr,sum/2,0) + sum % 2 << endl;

    return 0;
    
}