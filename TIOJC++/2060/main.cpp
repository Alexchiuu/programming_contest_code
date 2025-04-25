#include <bits/stdc++.h>

using namespace std;

struct group{
    int orip;
    int aftp;
    int oriN;
    int aftN;
    int orisum[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int aftsum[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    bool iforicrt[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    bool ifaftcrt[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
};

int main(){

    int T;
    cin >> T;

    int N, M, S, K;
    for(int i = 0; i < T; i++){

        cin >> N >> M >> S >> K;
        int t,g,p,a,b;
        vector<group> team(N);
        for(int j = 0; j < S; j++){
            cin >> t >> g >> p >> a >> b;
            if(team[g].iforicrt[p] == false){
                if (a == 0){
                    team[g].orisum[p]++;
                }else{
                    team[g].iforicrt[p] = true;
                    team[g].orip++;
                    team[g].oriN += t + 20 * team[g].orisum[p];
                }
            }
            if(team[g].ifaftcrt[p] == false){
                if (a == 0){
                    team[g].aftsum[p]++;
                }else{
                    team[g].ifaftcrt[p] = true;
                    team[g].aftp++;
                    team[g].aftN += t + 20 * team[g].aftsum[p];
                }
            }
        }
        
        
    }



    
}