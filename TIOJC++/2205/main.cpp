#include <iostream> 

using namespace std;

int cham1[26] {};
int cham2[26] {};
int cham3[26] {};

void clear(){
    for(int j = 0; j < 26; j ++){
        cham1[j] = 0;
    }
    for(int j = 0; j < 26; j ++){
        cham2[j] = 0;
    }
    for(int j = 0; j < 26; j ++){
        cham3[j] = 0;
    }
}
bool check(){
    for(int i = 0; i < 26; i++){
        if(!(cham1[i] == cham2[i] && cham2[i] == cham3[i])){
            clear();
            return false;
        }
    }
    clear();
    return true;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string S = "abbaab",str;
    int N = 6, Q = 1;
    cin >> N >> Q;

    cin >> S;
    int t = 1, l = 1, r = 6;

    for(int i = 0; i < Q; i++){
        
        str = "";
        cin >> t >> l >> r;
        if(t == 1){
            if((r - l + 1) % 3 == 0){
                for(int j = l - 1; j < l - 1 + (r - l + 1) / 3; j++){
                    cham1[S[j] - 'a'] ++;
                    str.push_back(S[j]);
                }
                for(int j = l - 1 + str.length(); j < l - 1 + 2 * str.length(); j ++){
                    cham2[S[j] - 'a'] ++;
                }
                for(int j = l - 1 + 2 * str.length(); j < l - 1 + 3 * str.length(); j ++){
                    cham3[S[j] - 'a'] ++;
                }
                if(check() == false){
                    cout << 0 << endl;
                    continue;
                }
                int ans = 1;
                for(int j = l - 1 + str.length(); j < l - 1 + 2 * str.length(); j ++){
                    if(str[str.length() - (j - (l - 1 + str.length())) - 1] != S[j]){
                        ans = 0;
                        break;
                    }
                }
                if(ans == 0){
                    cout << 0 << endl;
                    continue;
                }
                for(int j = l - 1 + 2 * str.length(); j < l - 1 + 3 * str.length(); j ++){
                    if(str[j - (l - 1 + 2 * str.length())] != S[j]){
                        ans = 0;
                        break;
                    }
                }
                if(ans == 0){
                    cout << 0 << endl;
                }else{
                    cout << 1 << endl;
                }
                continue;
            }
            cout << 0 << endl;
        }else if(t == 2){
            int swap;
                swap = S[l - 1];
                S[l - 1] = S[r - 1];
                S[r - 1] = swap;
        }
    }

    return 0;
    
}