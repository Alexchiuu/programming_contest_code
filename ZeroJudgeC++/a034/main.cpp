#include <iostream> 
#include <stack>
using namespace std;

int main(){

    stack<int> output;
    int input {};
    while(cin >> input){

        while (input){
            output.push(input % 2);
            input /= 2;
        }

        while (!output.empty()){
            cout << output.top();
            output.pop();
        }

        cout << endl;
    }
    return 0;   
}