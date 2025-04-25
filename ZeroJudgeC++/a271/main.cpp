#include <iostream> 

using namespace std;

const char RED {'1'};
const char WHITE {'2'};
const char YELLOW {'3'};
const char BLACK {'4'};
const char NOTHING {'0'};

int main(){

    size_t times = 1;
    int x {}, y {}, z {}, w {}, n {}, m {};
    cin >> times;

    for(size_t i = 0; i < times; i ++){

        bool alive = true;
        int poisoned = 0;
        string todo = {""};

        
        cin >> x >> y >> z >> w >> n >> m;
        cin.ignore();
        getline(cin, todo);
        
        if(todo == ""){
            cout << m << "g" << endl;
        }else{
            for(size_t j = 0; j < todo.length(); j += 2){
                m -= poisoned;
                if(m <= 0){
                    alive = false;
                    break;
                }
                switch (todo[j]){
                    case RED:
                        m += x;
                        break;
                    case WHITE:
                        m += y;
                        break;
                    case YELLOW:
                        m -= z;
                        break;
                    case BLACK:
                        m -= w;
                        poisoned += n;
                        break;
                    case NOTHING:
                        break;   
                }
                if(m <= 0){
                    alive = false;
                    break;
                }
            }
            if(alive){
                cout << m << "g" << endl;
            }else{
                cout << "bye~Rabbit" << endl;
            }
            
        }
    }

    return 0;
    
}