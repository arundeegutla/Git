#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    vector<string> grid;
    for(int i = 0; i < 3; i++)
        grid.push_back(next());

    auto go = [&](char target) -> bool {
        bool won = false;
        for(int i = 0; i < 3; i++){
            if(grid[i][0] == target && grid[i][1] == target && grid[i][2] == target){
                won = true;
            }
            if(grid[0][i] == target && grid[1][i] == target && grid[2][i] == target){
                won = true;
            }
        }
        won |= grid[2][0] == target && grid[1][1] == target && grid[0][2] == target;
        won |= grid[0][0] == target && grid[1][1] == target && grid[2][2] == target;
        return won;
    };

    bool plus = go('+');
    bool X = go('X');
    bool O = go('O');

    if(plus && !X && !O){
        cout << "+\n";
    } else if (X && !plus && !O){
        cout << "X\n";
    } else if (O && !X && !plus){
        cout << "O\n";
    } else {
        cout << "DRAW\n";
    
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}