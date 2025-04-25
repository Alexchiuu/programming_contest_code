#include <bits/stdc++.h> 

using namespace std;

vector<bool> x(8,false);
vector<bool> yax(15,false);
vector<bool> ymx(15,false);

int f(vector<string> &chessboard,int l){
    if(l == 7){
        int sum = 0;
        for(int i = 0; i < 8; i++){
            if(chessboard[l][i] == '*') continue;
            if(yax[l + i]) continue;
            if(ymx[l - i + 7]) continue;
            if(x[i]) continue;
            sum ++;
        }
        return sum;
    }
    int sum = 0;
    for(int i = 0; i < 8; i++){
        if(chessboard[l][i] == '*') continue;
        if(yax[l + i]) continue;
        if(ymx[l - i + 7]) continue;
        if(x[i]) continue;
        x[i] = true;
        yax[l + i] = true;
        ymx[l - i + 7] = true;
        sum += f(chessboard,l + 1);
        x[i] = false;
        yax[l + i] = false;
        ymx[l - i + 7] = false;
    }
    return sum;
}

int main(){

    vector<string> board(8);
    for(int i = 0; i < 8; i++){
        cin >> board[i];
    }

    cout << f(board,0) << endl;

    return 0;
    
}