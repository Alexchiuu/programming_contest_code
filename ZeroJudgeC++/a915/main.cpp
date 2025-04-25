#include <iostream> 
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};
vector<point> points;

int bigger(int a, int b){
    if(points[a].x > points[b].x){
        return 1;
    }else if(points[b].x > points[a].x){
        return 0;
    }else{
        if(points[a].y > points[b].y){
            return 1;
        }else if(points[a].y < points[b].y){
            return 0;
        }else{
            return 2;
        }
    }
}

void swap(int a,int b){
    point p;
    p = points[a];
    points[a] = points[b];
    points[b] = p;
}

void quicksort(int left,int right){
    if(right <= left){
        return;
    }
    int sta = left;
    int i = left, j = right;
    while(i != j){

        while(bigger(j, sta) > 0 && i < j){
            j--;
        }

        while(bigger(sta, i) > 0 && i < j){
            i++;
        }
        if(i < j){
            swap(i, j);
        }  
    }
    swap(sta, i);
    quicksort(left, i - 1);
    quicksort(i + 1, right);
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    quicksort(0,n - 1);

    for(auto a: points){
        cout << a.x << " " << a.y << "\n";
    }

    return 0;
    
}