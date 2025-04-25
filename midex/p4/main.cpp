#include <iostream> 
#include <Windows.h>
using namespace std;

struct day
{
 int yy, mm, dd;
};
struct data
{
 char name[20]; 
 char classNo;
 struct day birthday;
 int math, eng;
};
struct data student[4] = {{"Marry ", 'A', {81, 2, 3}, 89, 90},
                            {"Tom", 'B', {80, 12, 13}, 79, 69},
                            {"Billy ", 'B', {80, 1, 29}, 81, 54},
                            {"John ", 'A', {81, 7, 22}, 69, 49}};

int max_eng(struct data eng_data[]){
    int max = 0;
    for(auto m: eng_data)
    return max;
}

float avg_math(struct data math_data[], char classNo){
    float sum {}, count {};
    for(int i = 0; i < 4; ++ i){
        if(math_data[i].classNo == classNo){
            sum += math_data[i].math;
            count ++;
        }
    }
    return sum / count;
}

int main(){

    SetConsoleOutputCP(CP_UTF8);


    cout << "(1)英文成績最佳的學生: " << student[max_eng(student)].name << endl;
    cout << "(2)A 班和 B 班學生的數學平均成績分別為: A: " << avg_math(student,'A') << ", B:" << avg_math(student,'B') << endl;



    return 0;
    
}
