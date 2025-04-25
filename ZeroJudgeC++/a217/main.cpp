#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    while(getline(cin,s)){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '?' || s[i] == '!' || s[i] == '.' || i == 0){
                while(!(s[i] <= 'z' && s[i] >= 'a') && i < s.size() - 1) i++;
                if(s[i] <= 'z' && s[i] >= 'a') s[i] = s[i] - 'a' + 'A';
            }else if(s[i] == 'i' && (i == s.size() - 1 || s[i + 1] == '?' || s[i + 1] == '!' || s[i + 1] == ' ' || s[i + 1] == '.' || s[i + 1] == ',') && (s[i - 1] == '?' || s[i - 1] == '!' || s[i - 1] == ' ' || s[i - 1] == '.' || s[i - 1] == ',')){
                s[i] = 'I';
            }
        }
        cout << s << '\n';
    }
    

    return 0;
}
