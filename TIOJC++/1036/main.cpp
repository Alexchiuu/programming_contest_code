#include <iostream> 

using namespace std;

const int MAX = 1e7 + 10;

int sum[MAX];
bool vis[MAX];

void init(){
    for(int i = 2; i < MAX; i++){
        if(!vis[i]){
            sum[i] ++;
            for(int j = i + i; j < MAX; j += i){
                vis[j] = true;
            }
        }
        sum[i] += sum[i - 1];
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int m,n;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> n;
        cout << sum[n] << '\n';
    }

    return 0;
    
}