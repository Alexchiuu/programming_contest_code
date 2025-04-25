#include <iostream> 
#include <vector>
#include <queue>

using namespace std;

const int forward{1};
const int right{2};
const int backward{3};
const int left{4};

struct mirror{
    int x;
    int y;
    int t;
};

int main(){

    vector<mirror> xlines;
    vector<mirror> ylines;
    int n;
    mirror m;
    mirror wall = {30001,300001,0};
    cin >> n;
    cin >> m.x >> m.y >> m.t;
    xlines.push_back(m);
    ylines.push_back(m);
    xlines.push_back(wall);
    ylines.push_back(wall);
    for(int i = 0; i < n - 1; i ++){
        cin >> m.x >> m.y >> m.t;
        int j;
        for(int j = 0; j < xlines.size() - 1; j ++){
            if(m.x > xlines[j].x){
                if(m.y > xlines[j].y){
                    j ++;
                    break;
                }
            }
        }
        cout << j << endl;
        xlines.insert(xlines.begin() + j,m);
        cout << "here" << endl;
        for(int j = 0; j < ylines.size() - 1; j ++){
            if(m.y > ylines[j].y){
                if(m.x > xlines[j].x){
                    j ++;
                    break;
                }
            }
        }
        cout << j << endl;
        ylines.insert(ylines.begin() + j, m);

    }
    for(auto a: xlines){
        cout << a.x << endl;
        cout << a.y << endl;
    }
    cout << "-----------------------------" << endl;
    for(auto a: ylines){
        cout << a.x << endl;
        cout << a.y << endl;
    }
    

    return 0;
    
}