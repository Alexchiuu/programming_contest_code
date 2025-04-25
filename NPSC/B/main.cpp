#include <bits/stdc++.h> 

using namespace std;

int main(){

    int N, M ,T;
    cin >> N >> M >> T;

    vector<pair<int,int> > arr(N);
    vector<vector<int> > g(N,vector<int> (M));
    string s;
    for(int i = 0; i < N; i ++){
        cin >> s;
        for(int j = 0; j < M; j ++){
            if(s[j] == 'X'){
                arr[i].first ++;
                arr[i].second ++;
                g[i][j] = 1;
            }
        }
    }

    cout << "aaa\n";
    
    sort(arr.begin(),arr.end());
    int sum = 0;
    int l = N;
    for(int i = 0; i < M; i ++){
        cout << "bbb\n";
        int tmp = 0;
        l -= arr[N - 1].first;
        arr[N - 1].first = 0;
        for(int j = 0; j < M; j ++){
            cout << "ccc\n";
            if(g[arr[N - 1].second][j] == 1){
                for(int k = 0; k < N; k ++){
                    cout << "eee\n";
                    if(g[k][j] == 1){
                        for(int l = 0; l < N; l ++){
                            cout << "ddd\n";
                            if(k == arr[l].second){
                                arr[l].first -= 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
        sum += l * (i + 1);
        sort(arr.begin(),arr.end());
    }
    cout << sum << '\n';

    return 0;
    
}