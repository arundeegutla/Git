#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int r = nextInt(), c = nextInt();
    vector<string> grid(r);
    for(auto& x : grid) x = next();

    int D[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == 'P'){
                for(auto d : D){
                    int nR = i+d[0];
                    int nC = j+d[1];
                    if(nR < 0 || nR >= r || nC < 0 || nC >= c) continue;
                    if(grid[nR][nC] == 'W'){
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "YES\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}