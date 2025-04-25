#include <iostream> 
#include <vector>

using namespace std;

void f(int level, vector<int>&);
bool used(int n,int level,vector<int>&);

int main(){

    int n {};
    while(cin >> n){
        vector<int> path(n);
        f(0,path);
    }

    return 0;
    
}
void f(int level, vector<int>& path){
    if(level == path.size()){
        for(auto a: path){
            cout << a;
        }
        cout << endl;
        return;
    }
    for(path[level] = path.size(); path[level] > 0;path[level] --){
        if(used(path[level],level,path))
            continue;
        f(level + 1,path);
    }

}
bool used (int n,int level,vector<int>& path){
    for(int i = 0; i < level; i ++){
        if(path[i] == n)
            return true;
    }
    return false;
}