#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > v(n + 2, vector<int> (m + 2, 1));
    vector<vector<int> > par(n + 2, vector<int> (m + 2,0));

    queue<pair<int,int>> BFSM;
    queue<pair<int,int>> BFS;

    bool flag = false;
    pair<int,int> end;

    for(int i = 1; i <= n; i ++){
        string s = "a";
        string input;
        cin >> input;
        s += input;
        for(int j = 1; j <= m; j ++){
            if(s[j] == '.') v[i][j] = 0;
            if(s[j] == 'M'){
                BFSM.push({i,j});
                v[i][j] = 1;
            }
            if(s[j] == 'A'){
                BFS.push({i,j});
                v[i][j] = 2;
                if(i == 1 || i == n || j == 1 || j == m){
                    flag = true;
                    end = {i,j};
                }
            }
        }
    }


    while(!BFS.empty() && (!flag)){
        queue<pair<int,int> > tmp;
        queue<pair<int,int> > tmpM;
        while(!BFSM.empty()){
            pair<int,int> ind = BFSM.front();
            //cout << "MON " << ind.first << ' ' << ind.second << '\n';
            BFSM.pop();
            if(v[ind.first + 1][ind.second] != 1){
                tmpM.push(make_pair(ind.first + 1, ind.second));
                v[ind.first + 1][ind.second] = 1;
            }
            if(v[ind.first - 1][ind.second] != 1){
                tmpM.push(make_pair(ind.first - 1, ind.second));
                v[ind.first - 1][ind.second] = 1;
            }
            if(v[ind.first][ind.second + 1] != 1){
                tmpM.push(make_pair(ind.first, ind.second + 1));
                v[ind.first][ind.second + 1] = 1;
            }
            if(v[ind.first][ind.second - 1] != 1){
                tmpM.push(make_pair(ind.first, ind.second - 1));
                v[ind.first][ind.second - 1] = 1;
            }
        }

        while(!BFS.empty()){
            pair<int,int> ind = BFS.front();
            //cout << "HUMAN " <<  ind.first << ' ' << ind.second << '\n';
            BFS.pop();
            if(v[ind.first + 1][ind.second] == 0){
                tmp.push(make_pair(ind.first + 1, ind.second));
                v[ind.first + 1][ind.second] = 2;
                par[ind.first + 1][ind.second] = 1;
                if(ind.first + 1 == n){
                    flag = true;
                    end = {ind.first + 1, ind.second};
                    break;
                }
            }
            if(v[ind.first - 1][ind.second] == 0){
                tmp.push(make_pair(ind.first - 1, ind.second));
                v[ind.first - 1][ind.second] = 2;
                par[ind.first - 1][ind.second] = 2;
                if(ind.first - 1 == 1){
                    flag = true;
                    end = {ind.first - 1, ind.second};
                    break;
                }
            }
            if(v[ind.first][ind.second + 1] == 0){
                tmp.push(make_pair(ind.first, ind.second + 1));
                v[ind.first][ind.second + 1] = 2;
                par[ind.first][ind.second + 1] = 3;
                if(ind.second + 1 == m){
                    flag = true;
                    end = {ind.first, ind.second + 1};
                    break;
                }
            }
            if(v[ind.first][ind.second - 1] == 0){
                tmp.push(make_pair(ind.first, ind.second - 1));
                v[ind.first][ind.second - 1] = 2;
                par[ind.first][ind.second - 1] = 4;
                if(ind.second - 1 == 1){
                    flag = true;
                    end = {ind.first, ind.second - 1};
                    break;
                }
            }
        }
        BFS = tmp;
        BFSM = tmpM;
    }   


    if(!flag){
        cout << "NO\n";
    }else{
        string ans;
        while(par[end.first][end.second] != 0){
            if(par[end.first][end.second] == 1){
                ans += "D";
                end.first --;
            }else if(par[end.first][end.second] == 2){
                ans += "U";
                end.first ++;
            }else if(par[end.first][end.second] == 3){
                ans += "R";
                end.second --;
            }else if(par[end.first][end.second] == 4){
                ans += "L";
                end.second ++;
            }     
        }
        cout << "YES" << '\n';
        cout << ans.size() << '\n';
        for(int i = ans.size() - 1; i >= 0; i --){
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}