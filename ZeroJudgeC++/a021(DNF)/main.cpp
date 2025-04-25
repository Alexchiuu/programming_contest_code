#include <iostream> 
#include <stack>

using namespace std;

void plusing(int length);
//void minusing();
void timesing(int length);
//void deviding();

stack<int> output;

string x,y;

int main(){

    char op;
    int length;
    cin >> x >> op >> y;
    if(x.length() > y.length())
        length = x.length();
    else
        length = y.length();
    switch (op){
        case '+':
            cout << "length : " << length << endl;
            plusing(length);
            break;
        case '-':
            //minusing();
            break;
        case '*':
            timesing(length);
            break;
        case '/':
            //deviding();
            break;
    }

    return 0;
    
}
void plusing(int length){

    //cout << x + y << endl;
    int xint[length] {},yint[length] {};
    for(int i = (x.length() - 1); i >= 0; i--){
        xint[(length - x.length() + i)] = x[i] - '0';
        //cout << "i : " << i << endl;
        //cout << "x[i] : " << x[i] - '0' << endl;
        //cout << "xint[" << (length - x.length() + i) << "] : " << xint[(length - x.length() + i)] << endl;
    }
    for(int i = y.length() - 1; i >= 0; i--){
        yint[length - y.length() + i] = y[i] - '0';
        //cout << "yint[" << length - y.length() + i << "] : " << yint[length - y.length() + i] << endl;  
    }
    int carry = 0;
    for(int i = length - 1; i >= 0; i--){
        output.push((xint[i] + yint[i]) % 10 + carry);
        cout << "push : " << output.top() << endl;
        carry = (xint[i] + yint[i]) / 10;
    }
    if(carry != 0)
        output.push(carry);
    while(!output.empty()){
        cout << output.top();
        output.pop();
    }
    cout << endl;
    return;

}
void timesing(int length){

    //cout << x + y << endl;
    int xint[length] {},yint[length] {},sum[500] {};
    for(int i = (x.length() - 1); i >= 0; i--){
        xint[(length - x.length() + i)] = x[i] - '0';
        cout << "xint[" << (length - x.length() + i) << "] : " << xint[(length - x.length() + i)] << endl;
    }
    for(int i = y.length() - 1; i >= 0; i--){
        yint[length - y.length() + i] = y[i] - '0';
        cout << "yint[" << length - y.length() + i << "] : " << yint[length - y.length() + i] << endl;  
    }
    int carry = 0;
    for(int j = length - 1; j >= 0; j--){
        for(int i = length - 1; i >= 0; i--){
            sum[501 - 2 * length + j + i] += xint[i] * yint[j] + carry;
            cout << "xint[i] : " << xint[i] << endl; 
            cout << "yint[j] : " << yint[j] << endl;
            cout << "The plus : " << xint[i] * yint[j] + carry << endl;
            if(sum[501 - 2 * length + j + i] >= 10){
                carry = sum[501 - 2 * length + j + i] / 10;
                sum[501 - 2 * length + j + i] = sum[501 - 2 * length + j + i] % 10;
            }
            cout << "1sum[" << 501 - 2 * length + j + i << "] : " << sum[501 - 2 * length + j + i] << endl;
            cout << "1cry : " << carry << endl;
            //cout << "push : " << output.top() << endl;
        }

        if(carry != 0){
            sum[500 - 2 * length + j] = carry;
            cout << "2cry : " << carry << endl;
            cout << "2sum[" << 500 - 2 * length + j << "] : " << sum[500 - 2 * length + j] << endl;
            carry = 0;
        }

    }

    bool on = false;
    for(int i = 0; i < 500; i++){
        if(sum[i] != 0){
            on = true;
        }
        if(on == true){
            cout << sum[i];
        }
    }
    cout << endl;
    return;

}