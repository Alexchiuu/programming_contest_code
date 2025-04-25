#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, k;
    cin >> n >> k;

    vector<int> input(n + 1);

    multimap<int,int> sum;

    for(int i = 1; i <= n; i ++) cin >> input[i];

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j ++){
            cout << input[i] + input[j] << ' ' << i * n << '\n';
            sum.insert({input[i]+input[j], i * n + j});
    }

    //cout << suma.size() << '\n';
    for(map<int,int>::iterator it = sum.begin(); it != sum.end(); it ++){
        cout << (*sum.find(k - (*it).first)).first << ' ' << (*sum.find(k - (*it).first)).second << '\n';
        if(sum.find(k - (*it).first)) != sum.end()) {
            cout << (*it).second / a.size() << ' '  << (*it).second % a.size() << ' ' << a.size() + sumb[k - (*it).first] / b.size() - 1 << ' ' << a.size() + sumb[k - (*it).first] % b.size() - 1 << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}