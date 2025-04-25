#include <iostream> 

using namespace std;

bool ifarmstrong(int );
int countDigits(int );
int powerof(int, int );
int main(){
    
    bool check {false};
    int begin, end;
    cin >> begin >> end;
    for(int i = begin; i <= end; i++){
        if(ifarmstrong(i)){
            cout << i << ' ';
            check = true;
        }
    }
    if(!check)
        cout << "none";
    
    cout << endl;
    
    return 0;
    
}
bool ifarmstrong(int num){
    int number{num};
    int n {countDigits(num)},split[countDigits(num)] {},sum {};
    for(int i = 0; i < n; i++){
        split[i] = num % 10;
        num /= 10;
    }
    for(int a: split){
        sum += powerof(a,n);
    }
    return (number == sum);
}
int countDigits(int n)
{
    string tmp;

    tmp = to_string(n);
    return tmp.size();
}
int powerof(int num, int power){
    int result = 1;
    for(int i = 0; i < power; i++){
        result *= num;
    }
    return result;
}