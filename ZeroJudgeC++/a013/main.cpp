#include <iostream>

using namespace std;

int main(){

    int n=0,k=1,s=0;
    int in[1000];
    char a,fourth,ninth;
    for(int i=0;i<1000;i++){
        in[i]=0;
    }
    while(a!='#'){
        cin.get(a);
        if(a==fourth){
            switch(a){
                case 'V':
                    in[n]+=(4*k);
                    break;
                case 'L':
                    in[n]+=(40*k);
                    break;
                case 'D':
                    in[n]+=(400*k);
                    break;
            }
            a='N';       
        }else if(a==ninth){
            switch(a){
                case 'X':
                    in[n]+=(9*k);
                    break;
                case 'C':
                    in[n]+=(90*k);
                    break;
                case 'M':
                    in[n]+=(900*k);
                    break;
            }
            a='N';
        }else{
            in[n]+=(s*k);
        }
        fourth='N';
        ninth='N';
        s=0;
        switch(a){
            case 'I':
                fourth='V';
                ninth='X';
                s=1;
                break;
            case 'V':
                in[n]+=(5*k);
                break;
            case 'X':
                fourth='L';
                ninth='C';
                s=10;
                break;
            case 'L':
                in[n]+=(50*k);
                break;
            case 'C':
                fourth='D';
                ninth='M';
                s=100;
                break;
            case 'D':
                in[n]+=(500*k);
                break;
            case 'M':
                in[n]+=(1000*k);
                break;
            case ' ':
                k*=-1;
                break;
            case '\n':
                k*=-1;
                n++;
                break;
        }
    }
    for(int i=0;i<n;i++){
        if(in[i]<0){
            in[i]*=-1;
        }else if(in[i]==0){
            cout<<"ZERO";
        }
        while(in[i]>=1000){
            in[i]-=1000;
            cout<<"M";
        }
        if(in[i]>=900){
            in[i]-=900;
            cout<<"CM";
        }
        if(in[i]>=500){
            in[i]-=500;
            cout<<"D";
        }
        if(in[i]>=400){
            in[i]-=400;
            cout<<"CD";
        }
        while(in[i]>=100){
            in[i]-=100;
            cout<<"C";
        }
        if(in[i]>=90){
            in[i]-=90;
            cout<<"XC";
        }
        if(in[i]>=50){
            in[i]-=50;
            cout<<"L";
        }
        if(in[i]>=40){
            in[i]-=40;
            cout<<"XL";
        }
        while(in[i]>=10){
            in[i]-=10;
            cout<<"X";
        }
        if(in[i]>=9){
            in[i]-=9;
            cout<<"IX";
        }
        if(in[i]>=5){
            in[i]-=5;
            cout<<"V";
        }
        if(in[i]>=4){
            in[i]-=4;
            cout<<"IV";
        }
        while(in[i]>=1){
            in[i]-=1;
            cout<<"I";
        }       
        cout<<endl;
    }

    return 0;
    
}