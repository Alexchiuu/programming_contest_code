#include <iostream> 
#include <vector>

using namespace std;

int n;
struct point{
    int sum;
    vector<int> pathto;
};

int pathcounting(int n, int f,vector<point> &points){
    if(points[f].pathto.size() == 1){
        return 0;
    }
    int count = points[f].pathto.size() - 1;
    for(int i = 0; i < points[f].pathto.size(); i++){
        if(n != points[f].pathto[i]){
            count += pathcounting(f, points[f].pathto[i],points);
        }
    }
    return count;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;  
    vector<point> vpoints(n);

    int x, y;
    for(int i = 0; i < n - 1; i ++){

        cin >> x >> y;

        vpoints[x - 1].pathto.push_back(y - 1);
        vpoints[y - 1].pathto.push_back(x - 1);

    }
    int max {};
    for(int i = 0; i < n; i ++){    
        if(vpoints[i].pathto.size() != 1){
            int arr[vpoints[i].pathto.size()] {};
            for(int j = 0; j < vpoints[i].pathto.size(); j++){
                arr[j] = pathcounting(i,vpoints[i].pathto[j],vpoints) + 1;
            }
            for(int j = 0; j < vpoints[i].pathto.size(); j++){
                for(int k = j + 1; k < vpoints[i].pathto.size(); k++){
                    vpoints[i].sum += arr[j] * arr[k];
                }
            }
            if(vpoints[i].sum > vpoints[max].sum ){
                max = i;
            }          
        }
    }
    cout << max + 1 << " " << vpoints[max].sum << endl;

    return 0;
    
}