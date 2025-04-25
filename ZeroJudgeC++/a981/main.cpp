#include <iostream> 
#include <vector>

using namespace std;

vector<int> arr;
int m;

void f(int n, int sum, vector<int> &ans){
    if(sum == m){
        for(auto a: ans){
            cout << a << " ";
        }
        cout << "\n";
        ans.pop_back();
        return;
    }
    for(int i = n; i < arr.size(); i++){
        if(sum + arr[i] <= m){
            ans.push_back(arr[i]);
            f(i + 1, sum + arr[i], ans);
        }else{
            return;
        }
    }
    return;
}

void sort(int left, int right){
    if(right <= left){
        return;
    }
    int i = left, j = right;
    int sta = left;
    while(i != j){
        while(arr[j] >= arr[sta] && i < j){
            j --;
        }
        while(arr[i] <= arr[sta] && i < j){
            i ++;
        }
        if(i < j){
            int swap;
            swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
        }
    }
    int swap;
    swap = arr[sta];
    arr[sta] = arr[j];
    arr[j] = swap;

    sort(left, i - 1);
    sort(i + 1, right);
}

int main(){

    int n;
    cin >> n >> m;

    int x;
    for(int i = 0; i < n; i ++){
        cin >> x;
        arr.push_back(x);
    }
    sort(0,n - 1);

    vector<int> ans;
    f(0, 0, ans);

    return 0;
    
}