#include <iostream>

using namespace std;

int main(){;
    int x,y;
    while(cin>>x>>y){
        int in[y][x];
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                cin>>in[j][i];
            }           
        }
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                cout<<in[i][j]<<" ";
            }
            cout<<endl;           
        }

    }

    
}