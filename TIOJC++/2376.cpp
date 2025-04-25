#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    stack<pair<int,int> > a;
    vector<int> save(n,0);

    int input;

    int sum = 0;
    
    cin >> input;
    a.push({0,input});
    for(int i = 1; i < n; i++){
        cin >> input;
        if(!a.empty()) sum += abs(input - a.top().second);
        int tmp = i;
        while(!a.empty() && input >= a.top().second){
            tmp = a.top().first;
            int tmph = a.top().second;
            a.pop();
            if(a.empty()) break;
            if(input > a.top().second){
                save[i - tmp] += a.top().second - tmph;
            }else{
                save[i - tmp] += input - tmph;
            }
        }
        a.push({tmp,input});
    }

    for(int i = 1; i < n; i ++){
        if(k / i >= save[i]){
            sum -= save[i] * 2;
            k -= i * save[i];
        }else{
            sum -= k / i * 2;
            break;
        }
    }


    cout << sum << '\n';

    return 0;
}