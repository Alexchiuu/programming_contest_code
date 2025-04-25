#include <iostream>
using namespace std;

string s {""}; 
int leftb {}, rightb {};

void dfs(int n) {
    if(leftb < rightb) {
        return;//end
    }
    if(s.size() == n * 2){ 

        if(leftb == rightb) {
            cout << s << '\n'; 
        }

    }else{
        s.push_back('('); 
        leftb ++; 
        dfs(n); 
        s.pop_back(); 
        leftb--;
        s.push_back(')'); 
        rightb ++; 
        dfs(n); 
        s.pop_back(); 
        rightb --;
    }
}
int main() {
    int n = 2; 
    //while(cin >> n){
        dfs(n);
    //}
    return 0;
}