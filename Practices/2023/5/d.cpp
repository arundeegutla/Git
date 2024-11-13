#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, m;
    cin >> n >> m;
    int oo = 1e9;

    vector<string> grid(n);
    for(auto& x : grid) 
        cin >> x;

    int D[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> dist(n, vector<int>(m, oo));
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(grid[i][j] != 'X'){
                dist[i][j] = -1;
                continue;
            } 

            for(auto d : D){
                int nR = i + d[0];
                int nC = j + d[1];
                // Edges or adjacent is not X
                if(nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] != 'X') {
                    q.push({i, j});
                    dist[i][j] = 1;
                    break;
                }
            }
        }
    }

    while(q.size()){
        auto [r, c] = q.front(); q.pop();
        int dis = dist[r][c];
        for(auto d : D){
            int nR = r + d[0];
            int nC = c + d[1];
            if(nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] != 'X') continue;
            if(dist[nR][nC] > dis + 1) {
                q.push({nR, nC});
                dist[nR][nC] = dis + 1;
            }
        }
    }

    int maxx = 0;
    for(auto arr : dist)
        maxx = max(maxx, *max_element(all(arr)));
        
    cout << maxx << "\n";
}
    
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}