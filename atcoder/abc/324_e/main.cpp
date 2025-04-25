#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5 + 10;

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string s,input;
    cin >> N >> s;
    int fr[s.length() + 1] = {};
    int bk[s.length() + 1] = {};
    for(int i = 0; i < N; i ++){
        cin >> input;
        int k = 0;
        for(int j = 0; j < s.length(); j ++, k ++){
            while(k < input.length() && input[k] != s[j]) k ++;
            if(k == input.length()){
                fr[j]++;
                break;
            }else if(j == s.length() - 1){
                fr[s.length()] ++;
            }
        }
        k = input.length() - 1;
        for(int j = s.length() - 1; j >= 0; j --, k --){
            while(k >= 0 && input[k] != s[j]) k--;
            if(k == -1){
                bk[s.length() - 1 - j]++;
                break;
            }else if(j == 0){
                bk[s.length()] ++;
            }
        }
    }
    for(int i = s.length(); i > 0; i --){
        bk[i - 1] += bk[i];
    }

    int ans = 0;
    for(int i = 0; i <= s.length(); i ++) ans += fr[i] * bk[s.length() - i];

    cout << ans << '\n';

    return 0;
}