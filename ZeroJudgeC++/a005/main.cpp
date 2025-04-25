#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t; 
    int a[t][5];

    for(int i=0;i<t;i++)
            cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
    
    for(int i=0;i<t;i++){
        if((a[i][3]-a[i][2])==(a[i][2]-a[i][1])&&(a[i][2]-a[i][1])==(a[i][1]-a[i][0]))
            a[i][4]=a[i][3]+(a[i][3]-a[i][2]);
        else if((a[i][3]/a[i][2])==(a[i][2]/a[i][1])&&(a[i][2]/a[i][1])==(a[i][1]/a[i][0]))
            a[i][4]=a[i][3]*(a[i][3]/a[i][2]);
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<5;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}