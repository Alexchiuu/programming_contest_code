#include <iostream> 
#include <iomanip>

using namespace std;



int main(){
    int T {}, N{}, M {};
    
    cin >> T;

    for(size_t i = 0; i < T; i ++){
        cin >> N >> M;
        int x = 0,y = 0,sum {0};
        int square[N][N] {};
        if(M == 1){
            while(sum != N * N){
                sum ++;
                while(!(x == N) && square[x][y] == 0){
                    square[x][y] = sum;
                    x ++;sum ++;
                }
                x --;y ++;
                while(!(y == N) && square[x][y] == 0){
                    square[x][y] = sum;
                    y ++;sum ++;
                }
                y --;x --;
                while(x >= 0 && square[x][y] == 0){
                    square[x][y] = sum;
                    x --;sum ++;
                }
                x ++;y--;
                while(y >= 0 && square[x][y] == 0){
                    square[x][y] = sum;
                    y --;sum ++;
                }
                y ++;x ++;sum --;

            }
        }else if(M == 2){
            while(sum != N * N){
                sum ++;
                while(!(y == N) && square[x][y] == 0){
                    square[x][y] = sum;
                    y ++;sum ++;
                }
                y --;x ++;
                while(!(x == N) && square[x][y] == 0){
                    square[x][y] = sum;
                    x ++;sum ++;
                }
                x --;y--;
                while(y >= 0 && square[x][y] == 0){
                    square[x][y] = sum;
                    y --;sum ++;
                }
                y ++;x --;
                while(x >= 0 && square[x][y] == 0){
                    square[x][y] = sum;
                    x --;sum ++;
                }
                x ++;y ++;sum --;
            }

        }
        for(int yp = 0; yp < N; yp ++){
            for(int xp = 0; xp < N; xp ++){
                cout << setw(5) << square[xp][yp];
            }
            cout << endl;
        }
    }
    return 0;
    
}
