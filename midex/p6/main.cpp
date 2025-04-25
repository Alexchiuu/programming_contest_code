#include <iostream> 
#include <iomanip>

using namespace std;

void odd(int N){
    double sum {};
    for(int i = 1; i <= N; i += 2){
        cout << "1/" << i;
        sum += 1.0/i;
        if(i != N)
            cout << '+';
    }
    cout << '=' << fixed << setprecision(2) << sum << endl;
    return;
}
void even(int N){
    double sum {};
    for(int i = 2; i <= N; i += 2){
        cout << "1/" << i;
        sum += 1.0/i;
        if(i != N)
            cout << '+';
    }
    cout << '=' << fixed << setprecision(2) << sum << endl;
    return;
}

int main(){

    int N;
    cin.ignore();
    cin.ignore();
    cin.ignore();
    cin.ignore();
    cin >> N;
    if(N % 2 == 0){
        even(N);
    }else{
        odd(N);
    }
    
    return 0;
    
}