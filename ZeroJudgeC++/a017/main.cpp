#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
int solver(int,int);
string input;
int main(){
  while(getline(cin,input)){
    int result = solver(0,(input.length()-1));
    cout << result <<endl; 
  } 
}

int solver(int begin, int end){
    int if_in = 0;
    for(int i = end; i >= begin; i--){
        if(input[i] == ')')
            if_in++;
        else if(input[i] == '(')
            if_in--;
        else if(input[i] == '+' && if_in==0)
            return solver(begin,(i-1))+solver((i+1),end);
        else if(input[i] == '-' && if_in==0)
            return solver(begin,(i-1))-solver((i+1),end);
    }
    for(int i = end; i >= begin; i--){
        if(input[i] == ')')
            if_in++;
        else if(input[i] == '(')
            if_in--;
        else if(input[i] == '*' && if_in == 0)
            return solver(begin,(i-1))*solver((i+1),end);
        else if(input[i] == '/' && if_in == 0)
            return solver(begin,(i-1))/solver((i+1),end);
        else if(input[i] == '%' && if_in == 0)
            return solver(begin,(i-1))%solver((i+1),end);
    }
    if(input[begin] == ' ')
        return solver((begin+1),end);
    if(input[end] == ' ')
        return solver(begin,(end-1));
    if((input[begin] == '(')&&(input[end] == ')'))
        return solver((begin+1),(end-1));
    if(isdigit(input[begin]) && isdigit(input[end])){
        int sum = 0;
        for(int i = begin; i <= end; i++){
            sum = sum * 10 + (input[i] - '0');
        }
        return sum;
    }

}