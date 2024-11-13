#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt(), m = nextInt();
    vector<vector<int>> grid(n, vector<int>(m));
    for(auto& arr: grid)
        for(auto& x : arr)
            x = nextInt();

    int D[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<bool>> visited(n, vector<bool>(m));

    auto go = [&](int i, int j, auto && go) -> ll {
        visited[i][j] = true;
        ll sum = grid[i][j];
        for(auto d : D){
            int nR = i + d[0];
            int nC = j + d[1];
            if(nR<0||nC<0||nR>=n||nC>=m||visited[nR][nC]||!grid[nR][nC]) continue;
            sum += go(nR, nC, go);
        }
        return sum;
    };

    ll maxx = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] && !visited[i][j])
                maxx = max(maxx, go(i, j, go));
    cout << maxx << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}