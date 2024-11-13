#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

unordered_map<int, pair<int, int>> numIndex;
ll grid[2024][2024];

void solve() {
    auto p = numIndex[nextInt()];
    cout << grid[p.first][p.second] << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);


    int rowStart = 1;
    for(int i = 1; i <= 2023; i++){
        int num = rowStart;
        for(int j = 1; j <= 2023; j++){
            numIndex[num] = {i, j};
            grid[i][j] = num;
            num += (j+1) + (i-1);
        }
        rowStart += i;
    }

    for(int i = 1; i <= 2023; i++)
        for(int j = 1; j <= 2023; j++){
            grid[i][j] *= grid[i][j];
            grid[i][j] += grid[i][j-1];
        }
    for(int i = 1; i <= 2023; i++)
        for(int j = 1; j <= 2023; j++)
            grid[i][j] += grid[i-1][j];

    int n = nextInt();
    while(n--) solve();
}