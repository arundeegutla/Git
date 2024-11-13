#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    vector<string> grid;
    for(int i = 0; i < 8; i++)
        grid.push_back(next());
    
    for(int i = 1; i < 7; i++){
        for(int j = 1; j < 7; j++){
            if(grid[i][j] == '#' && grid[i-1][j-1] == '#' && grid[i-1][j+1] == '#' && grid[i+1][j+1] == '#' && grid[i+1][j-1] == '#'){
                cout << i+1 << " " << j+1 << "\n"; 
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