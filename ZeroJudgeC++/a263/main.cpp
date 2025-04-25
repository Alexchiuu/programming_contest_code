#include <iostream> 

using namespace std;

const int normal[12] {31,28,31,30,31,30,31,31,30,31,30,31};
const int Leap[12] {31,29,31,30,31,30,31,31,30,31,30,31};

bool isLeap(int);
int main(){

    int y1, m1, d1, count1 {};
    int y2, m2, d2, count2 {};

    while(cin >> y1 >> m1 >> d1
            >> y2 >> m2 >> d2){

        count1 = 0;
        count2 = 0;

        for(int i = 0; i < y1; i++){
            if(isLeap(i)){
                count1 += 366;
            }else{
                count1 += 365;
            }
        }
        for(int i = 0; i < m1 - 1 ; i++){
            if(isLeap(y1)){
                count1 += Leap[i];
            }else{
                count1 += normal[i];
            }
        }
        count1 += d1;
        for(int i = 0; i < y2; i++){
            if(isLeap(i)){
                count2 += 366;
            }else{
                count2 += 365;
            }
        }
        for(int i = 0; i < m2 - 1 ; i++){
            if(isLeap(y2)){
                count2 += Leap[i];
            }else{
                count2 += normal[i];
            }
        }
        count2 += d2;
                
        cout << abs(count1 - count2) << endl;



    }


    return 0;
    
}
bool isLeap(int year)
{
    return((((year) % 4) == 0 && ((year) % 100) != 0) || ((year) % 400) == 0);
}