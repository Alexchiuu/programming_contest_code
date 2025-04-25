#include <iostream> 

using namespace std;

int main(){

    size_t sizet {10};

    double *p_salaries { new double[sizet]};
    int *p_students { new(nothrow) int[sizet]{}};
    double *p_scores { new(nothrow) double[sizet]{1,2,3,4,5}};

    if(p_scores){
        cout << "size of scores (it's a regular pointer) : " << sizeof(p_scores) << endl;
        cout << "Successfully allocated memory for scores." << endl;

        for( size_t i{}; i < sizet; ++i){

            cout << "value : " << p_scores[i] << ':' << *(p_scores + i) << endl;
        }
    }
    delete [] p_salaries;
    p_salaries = nullptr;

    delete [] p_students;
    p_students = nullptr;

    delete [] p_scores;
    p_scores = nullptr;

    //Static arrays v.s. Dynamic arrays

    int scores[10] {1,2,3,4,5,6,7,8,9,10};
    cout << "score size : " << size(scores) << endl;

    for(auto score : scores){

        cout << "value : " << score << endl;
    }

    int *p_scores1 = new int[10]{1,2,3,4,5,6,7,8,9,10};

    //cout << "p_score1 size : " << size(p_score1) << endl;//Don't work

    for(auto score : p_score1){

        cout << "value : " << score << endl;
    }
    return 0;
    
}