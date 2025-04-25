#include <iostream> 
#include <vector>

using namespace std;

struct tree{
    int x;
    int tall;
};

vector<tree> trees;
int sum{}, mx {},j {};

void check(){

    if(j >= 0){
        if(trees[j].x + trees[j].tall < trees[j + 1].x){
            if(trees[j].tall > mx){
                mx = trees[j].tall;
            }
            trees.erase(trees.begin() + j);
            sum ++;
            j --;
            check();
        }
    }

}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N {}, L{};
    
    cin >> N >> L;

    
    for(int i = 0; i < N; ++ i){
        tree T;
        cin >> T.x;
        trees.push_back(T);
    }
    for(int i = 0; i < N; ++ i){
        cin >> trees[i].tall;
    }
    
    
    

    //trees = /*{{10,30},{30,15},{50,55},{70,10},{100,55},{125,25}}*/ {{5,6}};

    for(; j < trees.size(); ++ j){
        if(j == 0){
            if((trees[j].x+trees[j].tall) > trees[j+1].x && (trees[j].x-trees[j].tall) < 0){
                continue;
            }
        }else if(j == trees.size() - 1){
            if((trees[j].x+trees[j].tall) > L && (trees[j].x-trees[j].tall) < trees[j-1].x){
                continue;
            }
        }else{
            if((trees[j].x+trees[j].tall) > trees[j+1].x && (trees[j].x-trees[j].tall) < trees[j-1].x){
                continue;
            }
        }
        if(trees[j].tall > mx){
            mx = trees[j].tall;
        }

        trees.erase(trees.begin() + j);
        j --;
        check();
        sum ++;
        
    }
    std::cout << sum << endl;
    std::cout << mx << endl;

    return 0;
    
}