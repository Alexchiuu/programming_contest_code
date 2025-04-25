#include <iostream> 
#include <algorithm>

using namespace std;

int main(){

    int N;
    cin >> N;

    int score[N];

    for(int i = 0; i < N; ++ i){
        cin >> score[i];
    }

    sort(score, score + N);

    for(auto a:score){
        cout << a << " ";
    }
    cout << endl;

    int worst_case {0};
    for(int i = 0; i < N; ++ i){
        if(score[i] < 60){
            worst_case = score[i];
            if(i == N - 1){
                cout << worst_case << endl;
                cout << "worst case" << endl;
                return 0;
            }
        }else if(i == 0){
            cout << "best case" << endl;
            cout << score[0] << endl;
            return 0;
        }else{
            cout << worst_case << endl;
            break;
        }
    }

    int best_case {100};
    for(int i = N - 1; i >= 0; -- i){
        if(score[i] >= 60){
            best_case = score[i];
        }else{
            cout << best_case << endl;
            break;
        }
    }

    return 0;
    
}