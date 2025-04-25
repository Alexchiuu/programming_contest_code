#include <iostream> 
#include <string.h>
#include <vector>

using namespace std;

bool isAnagram(string a, string b);

int main(){

    vector<string> input;
    vector<int> check;
    string orinput /*{"[/dog/, /ban/, /banana/, /nba/, /ananab/, /nnabaa/, /god/]"}*/, stringtov{""};
    getline(cin,orinput);
    orinput.erase(0,1);

    int count = 0;
    for(int i = 0; i < orinput.length(); ++ i){
        if(orinput[i] == ' '){
            input.push_back(stringtov);
            stringtov = "";
            count ++;
        }else{
            stringtov.push_back(orinput[i]);
        }
    }
    input.push_back(stringtov);
    for(int i = 0; i < input.size(); ++ i){
        input[i].erase(0,1);
        input[i].pop_back();
        input[i].pop_back();      
    }
    cout << '[';
    while(true){
        cout << "[\"" << input[0] << "\"";
        for(int i = 1; i < input.size(); ++ i){
            if(isAnagram(input[0],input[i])){
                cout << ", \"" << input[i] << "\"";
                check.push_back(i);
            }
        }
        for(int i = check.size() - 1; i >= 0; -- i){
            input.erase(input.begin() + check[i]);
        }
        check.clear();
        input.erase(input.begin());
        if(input.size() == 0){
            cout << ']';
            break;
        }else{
            cout << "], ";
        }
    }
    cout << ']' << endl;

    return 0;
    
}

bool isAnagram(string a, string b){
    if(a.length() != b.length()){
        return false;
    }
    int count[26] {};

    for(int i = 0; i < a.length(); ++ i){
        count[a[i] - 'a'] ++;
    }

    for(int i = 0; i < b.length(); ++ i){
        count[b[i] - 'a'] --;
        if(count[b[i] - 'a'] < 0){
            return false;
        }
    }

    return true;
}