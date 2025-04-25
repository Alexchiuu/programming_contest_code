#include <bits/stdc++.h> 

using namespace std;

const int N = 200001;

int arr[N][19];
int table[N];

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i][0];
    int power = 1;
    int sum = 0;
    for(int i = 1; i <= N; i++){
        if(i > power * 2){
            power *= 2;
            sum ++;
        }
        table[i] = sum;
    }

    power = 1;
    for(int i = 1; i < 19; i++){
        for(int j = 1;j <= n - power; j++){
            arr[j][i] = min(arr[j][i - 1],arr[j + power][i-1]);
        }
        power *= 2;
    }
    int a, b;
    for(int i = 1; i <= q; i++){
        cin >> a >> b;
        power = table[b - a + 1];
        cout << min(arr[a][power],arr[b - (1 << power) + 1][power]) << '\n';
    }

    return 0;
    
}