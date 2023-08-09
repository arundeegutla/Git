#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    vector<string> grid(8);
    for(auto& x : grid) x = next();

    for(int i = 0; i < 8; i++){
        char row = grid[i][0];
        if(row == 'R'){
            bool allsame = true;
            for(int j = 0; j < 8; j++)
                allsame &= grid[i][j] == row;
            if(allsame){
                cout << row << "\n";
                return;
            }
        }

        char col = grid[0][i];
        if(col == 'B'){
            bool allsame = true;
            for(int j = 0; j < 8; j++)
                allsame &= grid[j][i] == col;
            if(allsame){
                cout << col << "\n";
                return;
            }
        }
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}