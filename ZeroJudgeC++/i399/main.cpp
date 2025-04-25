#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());

    int max {};
    for(int i = 0; i < 3; i ++){
        int count = 0;
        for(int j = 0; j <3; j++){
            if(arr[i] == arr[j]){
                count ++;
            }
        }
        if(count > max){
            max = count;
        }
    }
    cout << max << ' ';
    for(int i = 2; i >= 0; i--){
        if(i != 2 && arr[i] == arr[i+1]) continue;
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
    
}