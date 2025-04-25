#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mx = 2e5 + 10;

int arr[mx] = {};
vector<double> cf = {0.04, 0.016, 0.0064, 0.00256};
vector<double> l = {0.00077,0.000583,0.000454,0.000294};
double cs = 0.001;
double gay = 0;

double check(double x){
    vector<double> tmp(5);
    double sum = 0;
    double k = 0;
    double avg;
    for(int i = 0; i < 4; i ++){
        tmp[i] = x*(l[i])/((cf[i] - x*(l[i]))*(cs - x*(l[i])));
        sum += tmp[i];
        cout << tmp[i] << '\n';
        if(tmp[i] < 0) return 1000000;
    }
    avg = sum / 4.0;
    for(int i = 0; i < 4; i ++){
        k += (tmp[i] - avg)*(tmp[i] - avg);
    }
    gay = avg;
    cout << "nva:" << x << '\n';
    cout << "sum:" << sum << '\n';
    cout << "dif:" << k << '\n';
    cout << "avg:" << avg << '\n';
    return k;
}

signed main(){


    for(double i = 0.98; i < 1.0; i += 0.001){
        if(check(i) < check(i + 0.001) && check(i) < check(i - 0.001)){
            check(i);
            break;
        }
    }

    return 0;
}